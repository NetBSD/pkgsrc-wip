# $NetBSD: dist.mk,v 1.2 2010/11/14 03:19:57 obache Exp $

PY_DISTVERSION=	2.7.1rc1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../wip/python27/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION:C/rc[0-9]$//}/
