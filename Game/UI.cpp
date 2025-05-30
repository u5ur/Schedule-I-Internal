#include "Render.h"

void Render::UI::DrawLine(Vector2 start, Vector2 end, Unity::Color color)
{
	Unity::GL::PushMatrix();
	if (Unity::Material::material->SetPass(0)) {
		Unity::GL::Begin(1);
		Unity::GL::GLColor(color);
		Unity::GL::Vertex({ start.x, start.y, 0 });
		Unity::GL::Vertex({ end.x, end.y, 0 });
		Unity::GL::End();
		Unity::GL::PopMatrix();
	}
}

void Render::UI::DrawString(Unity::Rect pos, Unity::String text, Unity::Color clr, bool centered, float font_size)
{
	auto content = Unity::GUIContent::Temp(&text);

	// Always use top-left alignment (no vertical shifting)
	Unity::GUISkin::label->SetAlignment(0); // TopLeft
	Unity::GUISkin::label->SetFontSize(font_size);

	Vector2 textSize = Unity::GUISkin::label->CalcSize(content);

	Unity::Rect DrawRect;
	DrawRect.x = centered ? pos.x - (textSize.x / 2.f) : pos.x;
	DrawRect.y = pos.y;
	DrawRect.width = textSize.x;
	DrawRect.height = textSize.y;

	Unity::GUI::SetColor({ 0,0,0,255 });
	Unity::GUI::Label({ DrawRect.x - 1, DrawRect.y, DrawRect.width, DrawRect.height }, content, Unity::GUISkin::label);
	Unity::GUI::Label({ DrawRect.x + 1, DrawRect.y, DrawRect.width, DrawRect.height }, content, Unity::GUISkin::label);
	Unity::GUI::Label({ DrawRect.x, DrawRect.y - 1, DrawRect.width, DrawRect.height }, content, Unity::GUISkin::label);
	Unity::GUI::Label({ DrawRect.x, DrawRect.y + 1, DrawRect.width, DrawRect.height }, content, Unity::GUISkin::label);

	Unity::GUI::SetColor(clr.GetUnityColor());
	Unity::GUI::Label({ DrawRect.x, DrawRect.y, DrawRect.width, DrawRect.height }, content, Unity::GUISkin::label);
}




void Render::UI::DrawRect(Unity::Rect rect, Unity::Color color, float round, float thickness)
{
	if (thickness <= 0.0f) return;

	float maxRounding = fmin(rect.width, rect.height) * 0.5f;
	round = fmin(round, maxRounding);

	float xMin = rect.x;
	float yMin = rect.y;
	float xMax = rect.x + rect.width;
	float yMax = rect.y + rect.height;
	float x1 = xMin + round;
	float y1 = yMin + round;
	float x2 = xMax - round;
	float y2 = yMax - round;

	const int segments = 64;
	const float delta = 0.5f * PI / segments;

	Unity::GL::PushMatrix();
	if (Unity::Material::material->SetPass(0)) {
		Unity::GL::Begin(1);
		Unity::GL::GLColor(color);

		Unity::GL::Vertex({ x1, yMin, 0 });
		Unity::GL::Vertex({ x2, yMin, 0 });

		Unity::GL::Vertex({ xMax, y1, 0 });
		Unity::GL::Vertex({ xMax, y2, 0 });

		Unity::GL::Vertex({ x2, yMax, 0 });
		Unity::GL::Vertex({ x1, yMax, 0 });

		Unity::GL::Vertex({ xMin, y2, 0 });
		Unity::GL::Vertex({ xMin, y1, 0 });

		auto AddCorner = [&](float cx, float cy, float startAngle) {
			for (int i = 0; i < segments; ++i) {
				float angle1 = startAngle + i * delta;
				float angle2 = startAngle + (i + 1) * delta;
				Unity::GL::Vertex({ cx + round * cosf(angle1), cy + round * sinf(angle1), 0 });
				Unity::GL::Vertex({ cx + round * cosf(angle2), cy + round * sinf(angle2), 0 });
			}
			};

		if (round > 0.0f) {
			AddCorner(x1, y1, PI);
			AddCorner(x2, y1, 1.5f * PI);
			AddCorner(x2, y2, 0.0f);
			AddCorner(x1, y2, 0.5f * PI);
		}

		Unity::GL::End();
	}
	Unity::GL::PopMatrix();
}


void Render::UI::DrawFilledRect(Unity::Rect rect, Unity::Color color, float round)
{
	if (round <= 0.0f) {
		Unity::GL::PushMatrix();
		if (Unity::Material::material->SetPass(0)) {
			Unity::GL::Begin(7);
			Unity::GL::GLColor(color);
			Unity::GL::Vertex({ rect.x, rect.y, 0 });
			Unity::GL::Vertex({ rect.x + rect.width, rect.y, 0 });
			Unity::GL::Vertex({ rect.x + rect.width, rect.y + rect.height, 0 });
			Unity::GL::Vertex({ rect.x, rect.y + rect.height, 0 });
			Unity::GL::End();
		}
		Unity::GL::PopMatrix();
		return;
	}

	float maxRounding = fmin(rect.width, rect.height) * 0.5f;
	round = fmin(round, maxRounding);

	float xMin = rect.x;
	float yMin = rect.y;
	float xMax = rect.x + rect.width;
	float yMax = rect.y + rect.height;
	float x1 = xMin + round;
	float y1 = yMin + round;
	float x2 = xMax - round;
	float y2 = yMax - round;

	const int segments = 64;
	const float delta = 0.5f * PI / segments;

	Unity::GL::PushMatrix();
	if (Unity::Material::material->SetPass(0)) {
		Unity::GL::Begin(4);
		Unity::GL::GLColor(color);
		Unity::GL::Vertex({ x1, y1, 0 });
		Unity::GL::Vertex({ x2, y1, 0 });
		Unity::GL::Vertex({ x2, y2, 0 });
		Unity::GL::Vertex({ x1, y1, 0 });
		Unity::GL::Vertex({ x2, y2, 0 });
		Unity::GL::Vertex({ x1, y2, 0 });
		Unity::GL::Vertex({ x1, yMin, 0 });
		Unity::GL::Vertex({ x2, yMin, 0 });
		Unity::GL::Vertex({ x2, y1, 0 });
		Unity::GL::Vertex({ x1, yMin, 0 });
		Unity::GL::Vertex({ x2, y1, 0 });
		Unity::GL::Vertex({ x1, y1, 0 });
		Unity::GL::Vertex({ x1, y2, 0 });
		Unity::GL::Vertex({ x2, y2, 0 });
		Unity::GL::Vertex({ x2, yMax, 0 });
		Unity::GL::Vertex({ x1, y2, 0 });
		Unity::GL::Vertex({ x2, yMax, 0 });
		Unity::GL::Vertex({ x1, yMax, 0 });
		Unity::GL::Vertex({ xMin, y1, 0 });
		Unity::GL::Vertex({ x1, y1, 0 });
		Unity::GL::Vertex({ x1, y2, 0 });
		Unity::GL::Vertex({ xMin, y1, 0 });
		Unity::GL::Vertex({ x1, y2, 0 });
		Unity::GL::Vertex({ xMin, y2, 0 });
		Unity::GL::Vertex({ x2, y1, 0 });
		Unity::GL::Vertex({ xMax, y1, 0 });
		Unity::GL::Vertex({ xMax, y2, 0 });
		Unity::GL::Vertex({ x2, y1, 0 });
		Unity::GL::Vertex({ xMax, y2, 0 });
		Unity::GL::Vertex({ x2, y2, 0 });

		auto AddCorner = [&](float cx, float cy, float startAngle) {
			for (int i = 0; i < segments; ++i) {
				float angle1 = startAngle + i * delta;
				float angle2 = startAngle + (i + 1) * delta;
				Unity::GL::Vertex({ cx, cy, 0 });
				Unity::GL::Vertex({ cx + round * cosf(angle1), cy + round * sinf(angle1), 0 });
				Unity::GL::Vertex({ cx + round * cosf(angle2), cy + round * sinf(angle2), 0 });
			}
		};

		AddCorner(x1, y1, PI);
		AddCorner(x2, y1, 1.5f * PI);
		AddCorner(x2, y2, 0.0f);
		AddCorner(x1, y2, 0.5f * PI);

		Unity::GL::End();
	}
	Unity::GL::PopMatrix();
}

bool Render::UI::Button(Unity::Rect rect, Unity::Color color, Unity::String text, float round)
{
	if (text.size > 0) {
		auto* label = Unity::GUIContent::Temp(&text);
		auto sz = Unity::GUISkin::label->CalcSize(label);
		if (rect.width < sz.x) rect.width = sz.x + 5;
		if (rect.height < sz.y) rect.height = sz.y;
	}

	static bool wasPressed = false;
	static int anim = 0;
	static Unity::Rect last;

	bool clicked = Unity::GUI::Button(&rect, Unity::GUIContent::Temp(new Unity::String(L"")), Unity::GUISkin::label);
	auto* evt = Unity::Event::GetCurrent();
	bool hover = rect.Contains(evt->GetMousePosition());
	bool pressed = hover && (evt->GetType() == Unity::EventType::MouseDown || evt->GetType() == Unity::EventType::MouseDrag);

	if (clicked) { wasPressed = true; anim = 5; last = rect; }

	if (wasPressed && anim > 0 && rect.x == last.x && rect.y == last.y) {
		float grow = 4.0f * (anim / 5.0f);
		rect.x -= grow / 2; rect.y -= grow / 2; rect.width += grow; rect.height += grow;
		if (--anim <= 0) wasPressed = false;
	}

	float dim = pressed ? 0.7f : (hover ? 0.9f : 1.0f);
	color.r *= dim; color.g *= dim; color.b *= dim;

	DrawFilledRect(rect, color, round);

	if (text.size > 0) {
		Unity::GUISkin::label->SetAlignment(4);
		Unity::GUISkin::label->SetFontSize(14);
		Unity::GUI::Label(rect, Unity::GUIContent::Temp(&text), Unity::GUISkin::label);
	}

	return clicked;
}

void Render::UI::SliderInt(Unity::Rect rect, Unity::String text, int* value, int min, int max)
{
	*value = std::clamp(*value, min, max);

	Unity::Color bgColor = Unity::Color(0.2f, 0.2f, 0.2f, 1.0f);
	DrawFilledRect(rect, bgColor, 6.0f);

	float normalized = float(*value - min) / float(max - min);
	float handleWidth = 10.0f;
	float handleX = rect.x + normalized * (rect.width - handleWidth);
	Unity::Rect handleRect = { handleX, rect.y, handleWidth, rect.height };

	Unity::Event* evt = Unity::Event::GetCurrent();
	if ((evt->GetType() == Unity::EventType::MouseDown || evt->GetType() == Unity::EventType::MouseDrag) &&
		rect.Contains(evt->GetMousePosition()))
	{
		float localX = evt->GetMousePosition().x - rect.x;
		float t = std::clamp(localX / rect.width, 0.0f, 1.0f);
		*value = static_cast<int>(roundf(t * (max - min) + min));
	}

	Unity::Color handleColor = Unity::Color(0.9f, 0.9f, 0.9f, 1.0f);
	DrawFilledRect(handleRect, handleColor, 4.0f);

	Unity::GUIContent* labelContent = Unity::GUIContent::Temp(&text);
	Unity::GUISkin::label->SetAlignment(3);
	Unity::GUISkin::label->SetFontSize(14);
	Unity::Rect labelRect = { rect.x + rect.width + 8, rect.y, Unity::GUISkin::label->CalcSize(labelContent).x, rect.height };
	Unity::GUI::Label(labelRect, labelContent, Unity::GUISkin::label);
}

void Render::UI::DrawWindow(Unity::Rect pos, Unity::Color color)
{
	Unity::Rect windowRect = { pos.x, pos.y, pos.width, pos.height };
	UI::DrawFilledRect(windowRect, color, 10);
}

void Render::UI::Checkbox(Unity::Rect rect, Unity::Color color, Unity::String text, bool* value)
{
	static std::unordered_map<void*, float> animState;

	const float switchWidth = 40.0f;
	const float switchHeight = 20.0f;
	const float knobWidth = 18.0f;
	const float knobHeight = 18.0f;
	const float knobPadding = 1.0f;
	const float textPadding = 8.0f;
	const float animationSpeed = 0.15f;

	Unity::Rect switchRect = { rect.x, rect.y + (rect.height - switchHeight) / 2, switchWidth, switchHeight };

	Unity::GUIContent* label = Unity::GUIContent::Temp(&text);
	float textWidth = Unity::GUISkin::label->CalcSize(label).x;

	Unity::Rect textRect = { switchRect.x + switchRect.width + textPadding, rect.y + (rect.height - switchHeight) / 2, textWidth, switchHeight };
	Unity::GUI::Label(textRect, label, Unity::GUISkin::label);

	Unity::Event* currentEvent = Unity::Event::GetCurrent();
	Unity::EventType eventType = currentEvent->GetType();
	bool isHovering = switchRect.Contains(currentEvent->GetMousePosition());
	bool isPressed = isHovering && (eventType == Unity::EventType::MouseDown || eventType == Unity::EventType::MouseDrag);

	if (Unity::GUI::Button(&switchRect, Unity::GUIContent::Temp(new Unity::String(L"")), Unity::GUISkin::label)) {
		*value = !(*value);
	}

	float& animX = animState[value];
	float targetX = *value ? 1.0f : 0.0f;
	animX = animX + (targetX - animX) * animationSpeed;

	Unity::Color backColor = *value ? color : Unity::Color{ 0.5f, 0.5f, 0.5f, 1.0f };
	if (isPressed) {
		backColor.r *= 0.8f;
		backColor.g *= 0.8f;
		backColor.b *= 0.8f;
	}

	Render::UI::DrawFilledRect(switchRect, backColor, 10);
	float knobX = switchRect.x + knobPadding + (switchRect.width - knobWidth - 2 * knobPadding) * animX;

	Unity::Rect knobRect = { knobX, switchRect.y + knobPadding, knobWidth, knobHeight };
	Render::UI::DrawFilledRect(knobRect, Unity::Color{ 1.0f, 1.0f, 1.0f, 1.0f }, 10);
}