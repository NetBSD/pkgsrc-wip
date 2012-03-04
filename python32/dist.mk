# $NetBSD: dist.mk,v 1.1.1.1 2012/03/04 07:21:44 obache Exp $

PY_DISTVERSION=	3.2.3rc1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../wip/python32/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python32/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION:C/rc[0-9]*$//}/
