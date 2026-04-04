#include <stdio.h>


void dfs(int** image, int imageSize, int* imageColSize,
         int r, int c, int originalColor, int newColor) {
    
    
    if (r < 0 || c < 0 || r >= imageSize || c >= imageColSize[0])
        return;

    
    if (image[r][c] != originalColor)
        return;

    
    image[r][c] = newColor;


    dfs(image, imageSize, imageColSize, r + 1, c, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r - 1, c, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r, c + 1, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r, c - 1, originalColor, newColor);
         }
int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int originalColor = image[sr][sc];

    
    if (originalColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    
    dfs(image, imageSize, imageColSize, sr, sc, originalColor, color);

    
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
