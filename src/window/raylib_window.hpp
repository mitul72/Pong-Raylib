
class Window{
public:
    int window_width = 1280;
    int window_height = 800;

    const float rect_height = static_cast<float>(window_height/4.0);
    const float rect_width = 20;
    const float rect_x_offset = 10;
    Vector2 ballPosition = { (float)window_width/2, (float)window_height/2 };
    Vector2 rectSize = {rect_width, rect_height};
    Vector2 p1Position = {rect_x_offset,static_cast<float>((window_height/2.0)-(rect_height/2.0))};
    Vector2 p2Position = {(float)window_width-rect_width-rect_x_offset,static_cast<float>((window_height/2.0)-(rect_height/2.0))};


    Window();
    ~Window();
    void create_window();

    void onWindowResize();
};