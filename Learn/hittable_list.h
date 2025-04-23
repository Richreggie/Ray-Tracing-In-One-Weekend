#pragma once
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>
#include "interval.h"

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }

    void add(shared_ptr<hittable> object) {                // 共享指针允许多个几何体共享一个公共实例（例如，一堆使用相同颜色材质的球体)
        objects.push_back(object);
    }

    //该函数是一个‌常量成员函数‌（不会修改对象状态）。//它显式覆盖了基类中声明的‌具有相同签名（包括 const）的虚函数‌。
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;
        // 记录某个物体的最近碰撞点// 通过指针调用该对象的hit方法
        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min,closest_so_far),temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif