/*
 * Adplug - Replayer for many OPL2/OPL3 audio file formats.
 * Copyright (C) 1999 - 2005 Simon Peter, <dn.tlp@gmx.net>, et al.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * dro.h - DOSBox Raw OPL Player by Sjoerd van der Berg <harekiet@zophar.net>
 * Refactored to better match dro2.h 
 *  by Laurence Dougal Myers <jestarjokin@jestarjokin.net>
 */


#include <stdint.h> // for uintxx_t
#include "player.h"

class CdroPlayer: public CPlayer
{
	protected:
		static const uint8_t iCmdDelayS = 0x00; // Wraithverge: fixed this with "static".
		static const uint8_t iCmdDelayL = 0x01; // Wraithverge: fixed this with "static".
		int iConvTableLen;
		uint8_t *piConvTable;

		uint8_t *data;
		int iLength;
		int iPos;
		int iDelay;


	public:
		static CPlayer *factory(Copl *newopl);

		CdroPlayer(Copl *newopl);
		~CdroPlayer();

		bool load(const std::string &filename, const CFileProvider &fp);
		bool update();
		void rewind(int subsong);
		float getrefresh();

		std::string gettype()
		{
			return std::string("DOSBox Raw OPL v0.1");
		}
};
