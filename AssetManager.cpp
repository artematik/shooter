#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr; // экземп€р ещЄ не создан

AssetManager::AssetManager()
{
	// проверка, что класс создаЄтс€ впервые
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	auto& texMap = sInstance->m_Textures;
	auto pairFound = texMap.find(filename);

	// проверка на наличие данной текстуры
	if (pairFound != texMap.end())
	{
		// если текстура найдена, то возврашаем еЄ
		return pairFound->second;
	}
	else
	{
		// иначе создаЄм новую запись и подгружаем текстуру
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{
	auto& sBufferMap = sInstance->m_SoundBuffer;
	auto pairFound = sBufferMap.find(filename);

	// проверка на наличие данного звука
	if (pairFound != sBufferMap.end())
	{
		// если звук найден, то возврашаем его
		return pairFound->second;
	}
	else
	{
		// иначе создаЄм новую запись и подгружаем звук
		auto& sBuffer = sBufferMap[filename];
		sBuffer.loadFromFile(filename);
		return sBuffer;
	}
}

sf::Font& AssetManager::GetFont(std::string const& filename)
{
	auto& fontMap = sInstance->m_Fonts;
	auto pairFound = fontMap.find(filename);

	// проверка на наличие данного звука
	if (pairFound != fontMap.end())
	{
		// если звук найден, то возврашаем его
		return pairFound->second;
	}
	else
	{
		// иначе создаЄм новую запись и подгружаем звук
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}

sf::Shader*  AssetManager::GetShader(std::string const& vsFile, std::string const& fsFile)
{
	auto& shaderMap = sInstance->m_Shaders;
	auto combinedKey = vsFile + ";" + fsFile;
	auto pairFound = shaderMap.find(combinedKey);

	if (pairFound != shaderMap.find(combinedKey))
	{
		return pairFound->second.get();
	}
	else
	{
		auto const& shader = (shaderMap[combinedKey] = std::make_unique<sf::Shader>());
		shader->loadFromFile(vsFile, fsFile);
		return shader.get();
	}
}