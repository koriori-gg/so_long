// #include "mlx.h"

// int main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
//     mlx_loop(mlx);
// }

#include "../include/so_long.h"
#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
    mlx_loop(mlx);
}
