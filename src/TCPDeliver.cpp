// Avisynth v2.5.  Copyright 2002 Ben Rudiak-Gould et al.
// Avisynth v2.6.  Copyright 2006 Klaus Post.
// Avisynth v2.6.  Copyright 2009 Ian Brabham.
// Avisynth+ project
// Last modification date: 20170117

// http://www.avisynth.org

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA, or visit
// http://www.gnu.org/copyleft/gpl.html .
//
// Linking Avisynth statically or dynamically with other modules is making
// a combined work based on Avisynth.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//
// As a special exception, the copyright holders of Avisynth give you
// permission to link Avisynth with independent modules that communicate
// with Avisynth solely through the interfaces defined in avisynth.h,
// regardless of the license terms of these independent modules, and to
// copy and distribute the resulting combined work under terms of your
// choice, provided that every copy of the combined work is accompanied
// by a complete copy of the source code of Avisynth (the version of
// Avisynth used to produce the combined work), being distributed under
// the terms of the GNU General Public License plus this exception.  An
// independent module is a module which is not derived from or based on
// Avisynth, such as 3rd-party filters, import and export plugins, or
// graphical user interfaces.

// TCPDeliver (c) 2004 by Klaus Post, (c) 2017 DJATOM

#include <TCPClient.h>
#include <TCPServer.h>

const AVS_Linkage *AVS_linkage = 0;

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit3(IScriptEnvironment* env, const AVS_Linkage* const vectors) {
    AVS_linkage = vectors;
    env->AddFunction("TCPServer", "c[port]i", Create_TCPServer, 0);
    env->AddFunction("TCPSource", "s[port]i[compression]s", Create_TCPClient, 0);
    return "TCPDeliver plugin for AviSynth+.";
}
