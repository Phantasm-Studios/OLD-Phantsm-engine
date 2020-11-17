#pragma once


#include "engine/array.h"
#include "engine/resource.h"
#include "engine/resource_manager.h"


namespace Lumix
{


struct Clip final : Resource
{
public:
	Clip(const Path& path, ResourceManager& manager, IAllocator& allocator)
		: Resource(path, manager, allocator)
		, m_data(allocator)
	{
	}

	ResourceType getType() const override { return TYPE; }

	void unload() override;
	bool load(u64 size, const u8* mem) override;
	int getChannels() const { return m_channels; }
	int getSampleRate() const { return m_sample_rate; }
	int getSize() const { return m_data.size() * sizeof(m_data[0]); }
	u16* getData() { return &m_data[0]; }
	float getLengthSeconds() const { return m_data.size() / float(m_channels * m_sample_rate); }

	static const ResourceType TYPE;

private:
	int m_channels;
	int m_sample_rate;
	Array<u16> m_data;
};


} // namespace Lumix