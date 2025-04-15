#pragma once

struct Color
{
	float r;
	float g;
	float b;
	float a;

	Color()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}

	Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color Rainbow()
	{
		static float r = 1.00f, g = 0.00f, b = 1.00f;
		static int cases = 0;
		switch (cases) {
		case 0: { r -= 0.006f; if (r <= 0) cases += 1; break; }
		case 1: { g += 0.006f; b -= 0.006f; if (g >= 1) cases += 1; break; }
		case 2: { r += 0.006f; if (r >= 1) cases += 1; break; }
		case 3: { b += 0.006f; g -= 0.006f; if (b >= 1) cases = 0; break; }
		default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
		}

		return Color(r, g, b, 1);
	}

	Color GetUnityColor()
	{
		return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}

	Color GetBrightColor()
	{
		return Color(r * 10, g * 10, b * 10, a / 255.0f);
	}

	Color Zero()
	{
		return Color(0, 0, 0, 0);
	}
};

struct Rect
{
	float x;
	float y;
	float width;
	float height;

	Rect(float x, float y, float x_rightsize, float y_downsize) {
		this->x = x;
		this->y = y;
		width = x_rightsize;
		height = y_downsize;
	}

	Rect() {
		this->x = 0;
		this->y = 0;
		width = 0;
		height = 0;
	}

	bool Contains(Vector2 point)
	{
		return point.x >= x && point.x < (x + width) && point.y >= y && point.y < (y + height);
	}
};

struct String {
	char zpad[0x10];
public:

	int size;
	wchar_t str[MAX_STRING_LEN + 1];

	String(const wchar_t* st)
	{
		size = static_cast<int>(std::min(std::wcslen((wchar_t*)st), static_cast<size_t>(128)));
		for (int i = 0; i < size; i++) {
			str[i] = st[i];
		}
		str[size] = 0;
	}

	const wchar_t* str_wcsstr(const wchar_t* str, const wchar_t* substr) {
		const wchar_t* p = str;
		const wchar_t* q = substr;

		while (*str) {
			p = str;
			q = substr;
			while (*p && *q && *p == *q) {
				p++;
				q++;
			}
			if (*q == L'\0') {
				return str;
			}
			str++;
		}

		return nullptr;
	}

	int find(const wchar_t* substr) {
		return str_wcsstr(str, substr) != nullptr ? 0 : -1;
	}

	static inline constexpr auto npos{ static_cast<size_t>(-1) };

	static String* New(const char* str) {
		DWORD64 handle = il2cpp::NewString(str);
		return reinterpret_cast<String*>(handle);
	}
};

template<typename T>
struct List
{
	T Get(uint32_t idx)
	{
		const auto internal_list = reinterpret_cast<uintptr_t>(this + 0x20);
		return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
	}

	T GetValue(uint32_t idx) {
		const auto list = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
		const auto internal_list = list + 0x20;
		return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
	}

	T operator[](uint32_t idx) { return Get(idx); }
	const uint32_t GetSize() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }
};

struct Ray
{
	Vector3 Origin;
	Vector3 direction;

	Ray(Vector3 origin, Vector3 direction)
	{
		this->Origin = origin;
		this->direction = direction;
		this->direction = direction.Normalize();
	}
};