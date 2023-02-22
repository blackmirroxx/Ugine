#include "pch.h"
#include "Ugine/Scene.h"
#include "Ugine/Renderer.h"
#include "gmock/gmock.h"


class Mock2DComponent final: public ugine::Component2D {
public:
    Mock2DComponent(): ugine::Component2D("mock") {}
    [[nodiscard]] std::tuple<std::string, ugine::AssetProps> initial_rendering() const noexcept override {
        return {"attack", {0,0, 100, 100, 1 }};
    }
};

class MockTextureManager final : public ugine::TextureManager {
public:
    MOCK_METHOD( void, render,(const std::string&, const ugine::AssetProps&) , ( const,  override) );
};

TEST(SDLTextureManager, RenderScene) {
    auto first_scene = ugine::Scene2D("first_scene");
    auto texture_manager = MockTextureManager();
    auto component = std::make_unique<Mock2DComponent>();
    first_scene.add_component(std::move(component));
    EXPECT_CALL(texture_manager, render_scene("attack", testing::_));
    texture_manager.render_scene(first_scene);
}