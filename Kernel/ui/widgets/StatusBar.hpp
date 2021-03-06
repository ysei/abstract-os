/*
 * AbastractOS
 * Copyright (C) 2011 Davide Gessa
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <ctype.h>
#include <Device.hpp>
#include <list.hpp>
#include <ui/Rendering.hpp>


/** \addtogroup ui
 * @{
 */
class UiManager;

namespace Ui
{

class Widget
{
	public:
							Widget();
							~Widget();

		virtual void		Draw(unsigned x0, unsigned y0, unsigned x1, unsigned y1, unsigned alpha);
		
		Widget *			Next;				///< Next widget

	private:
		UiManager *			m_UiMan;			///< Ui manager
		Rendering *			m_Rend;				///< Rendering engine
	
};

};


/** @} */


#endif
