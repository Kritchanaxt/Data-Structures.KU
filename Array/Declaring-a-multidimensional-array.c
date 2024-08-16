
//! การประกาศอาร์เรย์แบบหลายมิติ

#include <stdio.h>

int main() {
    // ประกาศอาร์เรย์สองมิติ (ตาราง) ขนาด 3x3
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // แสดงผลอาร์เรย์สองมิติ
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}