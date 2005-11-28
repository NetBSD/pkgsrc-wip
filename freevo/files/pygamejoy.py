# -*- coding: iso-8859-1 -*-
# -----------------------------------------------------------------------
# pygamejoy.py - Alternative joystick plugin by David Howland 
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

        self.HMIN = 0
        self.HMAX = 0
        self.VMIN = 0
        self.VMAX = 0
        self.UnCal = 1

        # ok, joystick is working
        plugin.DaemonPlugin.__init__(self)
        
        self.poll_interval  = 1
        self.poll_menu_only = False


    def poll(self):
        command = ''

	# buttons are first priority
        for i in range(self.Joystick.get_numbuttons()):
            if(self.Joystick.get_button(i)):
                if ((self.UnCal == 1) & (i == 0)):
                    self.UnCal = 0
                else:
                    button = "button %d" % (i + 1)
                    command = config.JOY_CMDS.get(button, '')

	# axis are last priority
        if command == '':
            for i in range(2):
                value = self.Joystick.get_axis(i)
                if (i == 0):
                    if (value > self.HMAX):
                        self.HMAX = value
                    if (value < self.HMIN):
                        self.HMIN = value
                    if (value > (self.HMAX*0.9)):
                        if self.UnCal != 1:
                            command = config.JOY_CMDS['right']
                    if (value < (self.HMIN*0.9)):
                        if self.UnCal != 1:
                            command = config.JOY_CMDS['left']
                if (i == 1):
                    if (value > self.VMAX):
                        self.VMAX = value
                    if (value < self.VMIN):
                        self.VMIN = value
                    if (value > (self.HMAX*0.9)):
                        if self.UnCal != 1:
                            command = config.JOY_CMDS['down']
                    if (value < (self.HMIN*0.9)):
                        if self.UnCal != 1:
                            command = config.JOY_CMDS['up']

	# if we have something to do
        if command != '':
            command = rc.key_event_mapper(command)
            if command:
                rc.post_event(command)
		sleep(0.1)

