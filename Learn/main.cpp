#include "rtweekend.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;

    cam.render(world);
}





//4.23 主函数代替相机的功能
//#include "rtweekend.h"
//
//#include "color.h"
//#include "hittable.h"
//#include "hittable_list.h"
//#include "sphere.h"
//
//#include <iostream>
//
//color ray_color(const ray& r, const hittable& world) {
//    hit_record rec;
//    if (world.hit(r, interval(0, infinity), rec)) {
//        return 0.5 * (rec.normal + color(1, 1, 1));
//    }
//
//    vec3 unit_direction = unit_vector(r.direction());
//    auto a = 0.5 * (unit_direction.y() + 1.0);
//    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
//}
//
//int main() {
//
////视口
//    auto aspect_ratio = 16.0 / 9.0;
//    int image_width = 400;
//
//    // 计算图像高度，并确保至少为1。
//    int image_height = int(image_width / aspect_ratio);
//    image_height = (image_height < 1) ? 1 : image_height;
//
//// World
//
//    hittable_list world;
//
//    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
//    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
//
//// Camera
//    auto focal_length = 1.0;
//    auto viewport_height = 2.0;// 视口宽度小于1是可以的，因为它们是实值。
//    auto viewport_width = viewport_height * (double(image_width) / image_height);
//    auto camera_center = point3(0, 0, 0);
//
//    // 计算水平和垂直视口边缘上的向量。
//    auto viewport_u = vec3(viewport_width, 0, 0);
//    auto viewport_v = vec3(0, -viewport_height, 0);
//
//    // 计算从像素到像素的水平和垂直增量向量。
//    auto pixel_delta_u = viewport_u / image_width;
//    auto pixel_delta_v = viewport_v / image_height;
//
//    // 计算左上角像素的位置。从左上角开始渲染
//    auto viewport_upper_left = camera_center
//        - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
//    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
//
//
//
//// Render
//    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
//
//    for (int j = 0; j < image_height; j++) {
//        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
//        for (int i = 0; i < image_width; i++) {
//            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
//            auto ray_direction = pixel_center - camera_center;
//            ray r(camera_center, ray_direction);
//
//            color pixel_color = ray_color(r, world);
//            write_color(std::cout, pixel_color);//vs的终端输出有问题，需要在cmd中转换为ppm文件，否则文件编码为UTF-16LE;目前通过修改powershell的配置文件已永久完善
//        } 
//    }
//
//    std::clog << "\rDone.                 \n";
//}




//第一可输出数据流的文件
//int main() {
//
// 
//       // Image
//
//        int image_width = 256;
//        int image_height = 256;
//
//        // Render
//
//        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
//
        //for (int j = 0; j < image_height; j++) {
        //    std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        //    for (int i = 0; i < image_width; i++) {
        //        auto r = double(i) / (image_width - 1);
        //        auto g = double(j) / (image_height - 1);
        //        auto b = 0.0;

        //        int ir = int(255.999 * r);
        //        int ig = int(255.999 * g);
        //        int ib = int(255.999 * b);

                //std::cout << ir << ' ' << ig << ' ' << ib << '\n';
//            }
//        }
//        std::clog << "\rDone.                 \n";
//}

//进度条
//float progress = 100.0f * (image_height - j) / image_height;
//std::clog << "\r["
//<< std::string(progress / 5, '=') << ">"
//<< std::string(20 - progress / 5, ' ') << "] "
//<< int(progress) << "% " << std::flush;