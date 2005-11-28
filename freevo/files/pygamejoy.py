# -*- coding: iso-8859-1 -*-
# -----------------------------------------------------------------------
# pygamejoy.py - Alternative joystick plugin by David Howland 
# -----------------------------------------------------------------------
# Activate this module with the following lines in your config file:
#   plugin.remove('joy')
#   plugin.activate('pygamejoy')
# Configure this module with lines such as these:
#   JOY_DEV = 1
#   JOY_CMDS = {
#     'a2 neg'         : 'UP'      ,
#     'a2 pos'         : 'DOWN'    ,
#     'a1 neg'         : 'LEFT'    ,
#     'a1 pos'         : 'RIGHT'   ,
#     'h1 up'          : 'UP'      ,
#     'h1 down'        : 'DOWN'    ,
#     'h1 left'        : 'LEFT'    ,
#     'h1 right'       : 'RIGHT'   ,
#     'button 1'       : 'PLAY'    ,
#     'button 2'       : 'PAUSE'   ,
#     'button 3'       : 'STOP'    ,
#     'button 4'       : 'ENTER'   ,
#     'button 9'       : 'EXIT'    ,
#     'button 10'      : 'SELECT'  ,
#   }
# -----------------------------------------------------------------------
# Freevo - A Home Theater PC framework
# Copyright (C) 2003 Krister Lagerstrom, et al. 
# Please see the file freevo/Docs/CREDITS for a complete list of authors.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MER-
# CHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
# Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# ----------------------------------------------------------------------- */


import sys
import os
import select
import struct
import traceback
from time import sleep

import pygame
from pygame.locals import *

import config
import plugin
import rc

rc = rc.get_singleton()

class PluginInterface(plugin.DaemonPlugin):

    def __init__(self):
        self.plugin_name = 'JOY'
        self.device_name = ''
     
        if config.JOY_DEV == 0:
            self.reason = 'Joystick input module disabled'
            return

        pygame.joystick.init()

        num_joy = pygame.joystick.get_count()
        print "Found %d joysticks." % num_joy

        if num_joy < 1:
            self.reason = 'No joysticks found'
            return

        self.Joystick = pygame.joystick.Joystick(config.JOY_DEV-1)
        self.Joystick.init()
        print "Using joystick:", self.Joystick.get_name()
        print "with: %d axis %d hats %d buttons" % (self.Joystick.get_numaxes(),self.Joystick.get_numhats(),self.Joystick.get_numbuttons())

        self.MIN = []
        self.MAX = []
        for i in range(self.Joystick.get_numaxes()):
	    self.MIN.append(-0.5)
	    self.MAX.append(0.5)

        # ok, joystick is working
        plugin.DaemonPlugin.__init__(self)
        
        self.poll_interval  = 1
        self.poll_menu_only = False


    def poll(self):
        command = ''

        # buttons are first priority
        for i in range(self.Joystick.get_numbuttons()):
            if(self.Joystick.get_button(i)):
                button = "button %d" % (i + 1)
                command = config.JOY_CMDS.get(button, '')

        # hats are second priority
        if command == '':
	    hatstring = ''
            for i in range(self.Joystick.get_numhats()):
                value = self.Joystick.get_hat(i)
                if(value[1] == 1):
                    hatstring = "h%d up" % (i + 1)
                if(value[1] == -1):
                    hatstring = "h%d down" % (i + 1)
                if(value[0] == -1):
                    hatstring = "h%d left" % (i + 1)
                if(value[0] == 1):
                    hatstring = "h%d right" % (i + 1)
            if hatstring != '':
                command = config.JOY_CMDS.get(hatstring, '')

        # axis are last priority
        if command == '':
	    joystring = ''
            for i in range(self.Joystick.get_numaxes()):
                value = self.Joystick.get_axis(i)
                if (value > self.MAX[i]):
                    self.MAX[i] = value
                if (value < self.MIN[i]):
                    self.MIN[i] = value
                if (value > (self.MAX[i] * 0.8)):
                    joystring = "a%d pos" % (i + 1)
                if (value < (self.MIN[i] * 0.8)):
                    joystring = "a%d neg" % (i + 1)
            if joystring != '':
                command = config.JOY_CMDS.get(joystring, '')

	# if we have something to do
        if command != '':
            command = rc.key_event_mapper(command)
            if command:
                rc.post_event(command)
		sleep(0.2)

