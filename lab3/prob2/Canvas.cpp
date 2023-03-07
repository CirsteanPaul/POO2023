#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height) {
	if (width >= Canvas::CanvasMaxLength || height >= Canvas::CanvasMaxLength) {
		throw "Canvas too large!";
	}

	this->height = height;
	this->width = width;
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->drawingBoard[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i <= ray; i++) {
		for (int j = 0; j <= ray; j++) {
			if (i + j == ray) {
				if (x + i < 0 || y + j < 0) continue;

				this->drawingBoard[x + i][y + j] = ch;

				if (x - i >= 0) {
					this->drawingBoard[x - i][y + j] = ch;
				}

				if (y - j >= 0) {
					this->drawingBoard[x + i][y - j] = ch;
				}

				if (x - i < 0 || y - j < 0) continue;

				this->drawingBoard[x - i][y - j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for(int k = 0 ; k <= ray; k ++)
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (i + j == k) {
				if (x + i < 0 || y + j < 0) continue;

				this->drawingBoard[x + i][y + j] = ch;

				if (x - i >= 0) {
					this->drawingBoard[x - i][y + j] = ch;
				}

				if (y - j >= 0) {
					this->drawingBoard[x + i][y - j] = ch;
				}

				if (x - i < 0 || y - j < 0) continue;

				this->drawingBoard[x - i][y - j] = ch;
			}
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	if (this->height <= y || this->width <= x) {
		return;
	}

	if (x < 0 || y < 0) {
		return;
	}

	this->drawingBoard[x][y] = ch;
}

void Canvas::Clear() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->drawingBoard[i][j] = ' ';
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < this->height; i++, std::cout<< '\n') {
		for (int j = 0; j < this->width; j++) {
			std::cout << this->drawingBoard[i][j];
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	if (left >= this->width || right >= this->width || top >= this->height
		|| bottom >= this->height) {
		return;
	}
	if (left < 0 || right < 0 || top < 0 || bottom < 0) {
		return;
	}

	for (int i = top; i <= bottom ; i ++) {
		this->drawingBoard[i][left] = ch;
		this->drawingBoard[i][right] = ch;
	}
	for (int j = left; j <= right; j++) {
		this->drawingBoard[top][j] = ch;
		this->drawingBoard[bottom][j] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	if (left >= this->width || right >= this->width || top >= this->height
		|| bottom >= this->height) {
		return;
	}
	if (left < 0 || right < 0 || top < 0 || bottom < 0) {
		return;
	}

	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			this->drawingBoard[i][j] = ch;
		}
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
		return;
	}

	if (x1 >= this->width || x2 >= this->width || y1 >= this->height || y2 >= this->height) {
		return;
	}

	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++) {
		this->drawingBoard[x][y] = ch;

		slope_error_new += m_new;

		if (slope_error_new >= 0) {
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}