/* Copyright (C) 2011 Rainmeter Project Developers
 *
 * This Source Code Form is subject to the terms of the GNU General Public
 * License; either version 2 of the License, or (at your option) any later
 * version. If a copy of the GPL was not distributed with this file, You can
 * obtain one at <https://www.gnu.org/licenses/gpl-2.0.html>.
 *
 * Code edited to export QImage by romanmatv */

#ifndef __COVER_H__
#define __COVER_H__

// TagLib
#include "taglib/fileref.h"
#include "taglib/apefile.h"
#include "taglib/apetag.h"
#include "taglib/asffile.h"
#include "taglib/attachedpictureframe.h"
#include "taglib/commentsframe.h"
#include "taglib/flacfile.h"
#include "taglib/id3v1genres.h"
#include "taglib/id3v2tag.h"
#include "taglib/mpcfile.h"
#include "taglib/mpegfile.h"
#include "taglib/mp4file.h"
#include "taglib/tag.h"
#include "taglib/taglib.h"
#include "taglib/textidentificationframe.h"
#include "taglib/tstring.h"
#include "taglib/vorbisfile.h"
#include <QImage>

class CCover
{
public:
	static bool GetCached(std::wstring& path);
	static bool GetLocal(std::wstring filename, const std::wstring& folder, std::wstring& target);
	static bool GetEmbedded(const TagLib::FileRef& fr, const std::wstring& target);
    static bool GetEmbedded(const TagLib::FileRef& fr, QImage& target);
	static std::wstring GetFileFolder(const std::wstring& file);
};

#endif
