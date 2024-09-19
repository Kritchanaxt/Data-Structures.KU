
//! การใช้การเข้าถึงสมาชิกของอาร์เรย์

#include <stdio.h>

int main() {
    // ประกาศอาร์เรย์และกำหนดค่าเริ่มต้น
    int numbers[5] = {10, 20, 30, 40, 50};

    // เข้าถึงและแสดงค่าของสมาชิกที่ตำแหน่งที่ 2 (index 1)
    printf("Element at index 1: %d\n", numbers[1]);

    // เปลี่ยนค่าในตำแหน่งที่ 3 (index 2)
    numbers[2] = 100;

    // แสดงอาร์เรย์ทั้งหมดหลังจากการเปลี่ยนแปลง
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}