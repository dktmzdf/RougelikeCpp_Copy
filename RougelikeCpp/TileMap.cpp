#include "TileMap.h"


//old version
/*TileMap::TileMap(const sf::Texture& texture, const sf::Vector2i& tileSize)
	: m_texture(texture), m_tileSize(tileSize)
{
}*/
//old version
void TileMap::load(const Map& map)
{
/*	const int width = map.getSize().x;
	const int height = map.getSize().y;
	m_vertices.resize(width * height * 4);
	for(int y = 0; y< height; ++y)
		for (int x = 0; x < width; ++x)
		{
			const int tileNumber = map.getTile(x, y).tileNumber;

			if (tileNumber < 0)
				continue;

			sf::Color color = { 255,255,255,0 };
			if (map.getTile(x, y).visible)
				color.a = 255;
			else if (map.getTile(x, y).explored)
				color.a = 75;
			else
				continue;

			const int tu = tileNumber % (m_texture.getSize().x / m_tileSize.x);
			const int tv = tileNumber / (m_texture.getSize().x / m_tileSize.x);

			sf::Vertex* quad = &m_vertices[(x + y * width) * 4];
			quad[0].position = sf::Vector2f((x + 0.f) * m_tileSize.x, (y + 0.f) * m_tileSize.y);
			quad[1].position = sf::Vector2f((x + 1.f) * m_tileSize.x, (y + 0.f) * m_tileSize.y);
			quad[2].position = sf::Vector2f((x + 1.f) * m_tileSize.x, (y + 1.f) * m_tileSize.y);
			quad[3].position = sf::Vector2f((x + 0.f) * m_tileSize.x, (y + 1.f) * m_tileSize.y);

			quad[0].texCoords = sf::Vector2f((tu + 0.f) * m_tileSize.x, (tv + 0.f) * m_tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1.f) * m_tileSize.x, (tv + 0.f) * m_tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1.f) * m_tileSize.x, (tv + 1.f) * m_tileSize.y);
			quad[3].texCoords = sf::Vector2f((tu + 0.f) * m_tileSize.x, (tv + 1.f) * m_tileSize.y);

			quad[0].color = color;
			quad[1].color = color;
			quad[2].color = color;
			quad[3].color = color;
		}*/
		
}

void TileMap::load(const sf::Texture& texture, const sf::Vector2i& tileSize)
{
	m_texture = &texture;
	m_tileSize = tileSize;

}

void TileMap::update(const Map& map)
{
	const int width = map.getSize().x;
	const int height = map.getSize().y;
	m_vertices.clear();
	m_vertices.resize(width * height * 4);
	for (int y = 0; y < height; ++y)
		for (int x = 0; x < width; ++x)
		{
			const int tileNumber = map.getTile(x, y).tileNumber;

			if (tileNumber < 0)
				continue;

			sf::Color color = { 255,255,255,0 };
			if (map.getTile(x, y).visible)
				color.a = 255;
			else if (map.getTile(x, y).explored)
				color.a = 75;
			else
				continue;

			const int tu = tileNumber % (m_texture->getSize().x / m_tileSize.x);
			const int tv = tileNumber / (m_texture->getSize().x / m_tileSize.x);

			sf::Vertex* quad = &m_vertices[(x + y * width) * 4];
			quad[0].position = sf::Vector2f((x + 0.f) * m_tileSize.x, (y + 0.f) * m_tileSize.y);
			quad[1].position = sf::Vector2f((x + 1.f) * m_tileSize.x, (y + 0.f) * m_tileSize.y);
			quad[2].position = sf::Vector2f((x + 1.f) * m_tileSize.x, (y + 1.f) * m_tileSize.y);
			quad[3].position = sf::Vector2f((x + 0.f) * m_tileSize.x, (y + 1.f) * m_tileSize.y);

			quad[0].texCoords = sf::Vector2f((tu + 0.f) * m_tileSize.x, (tv + 0.f) * m_tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1.f) * m_tileSize.x, (tv + 0.f) * m_tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1.f) * m_tileSize.x, (tv + 1.f) * m_tileSize.y);
			quad[3].texCoords = sf::Vector2f((tu + 0.f) * m_tileSize.x, (tv + 1.f) * m_tileSize.y);

			quad[0].color = color;
			quad[1].color = color;
			quad[2].color = color;
			quad[3].color = color;
		}

}

void TileMap::draw(sf::RenderWindow& window) const
{
	window.draw(m_vertices.data(), m_vertices.size(), sf::Quads, m_texture);
}
