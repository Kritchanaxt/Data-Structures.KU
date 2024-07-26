#include <stdio.h>
#include <stdlib.h>

// โครงสร้างโหนดในลิงก์ลิสต์แบบง่าย
struct Node {
    int data;           // ข้อมูลที่จัดเก็บ
    struct Node* next; // ตัวชี้ไปยังโหนดถัดไป
};
