#pragma once

class Location {
public:
	void Add(const Location& loc) {
		x += loc.x;
		y += loc.y;
	}
	int x;
	int y;

	bool operator==(const Location& rhs) const {
		return (x == rhs.x &&y == rhs.y);
	}

};