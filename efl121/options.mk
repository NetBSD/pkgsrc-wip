# $NetBSD: options.mk,v 0.2 2018/09/06 16:15:10 andyb Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.efl121

PKG_OPTIONS:systemd
CONFIGURE_ARGS+=        --enable-systemd
