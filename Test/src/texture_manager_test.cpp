#include "pch.h"
#include "ugine/scene.h"
#include "ugine/renderer.h"


class Mock2DComponent final: public ugine::Component2D {
public:
    Mock2DComponent(): ugine::Component2D("mock") {}
    [[nodiscard]] ugine::AssetProps initial_rendering() const noexcept override {
        return {"attack", 0,0, 100, 100, 1 };
    }
};

class MockTextureManager final : public ugine::TextureManager2D {
public:
    MOCK_METHOD( void, render_component,(const ugine::Component2D&, const ugine::AssetProps&) , ( const,  override) );
    void load_asset(const std:: string& asset_path, const std::string& asset_name) override  {

    }
};

TEST(SDLTextureManager, RenderScene) {
    auto first_scene = ugine::Scene2D("first_scene");
    auto texture_manager = MockTextureManager();
    auto component = std::make_unique<Mock2DComponent>();
    first_scene.add_component(std::move(component));
    EXPECT_CALL(texture_manager, render_component(testing::_, testing::_));
    texture_manager.render_scene(first_scene);
}