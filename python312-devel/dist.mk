# $NetBSD: dist.mk,v 1.2 2022/12/07 11:55:37 adam Exp $

PY_DISTVERSION=	3.12.0a6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../wip/python312-devel/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python312-devel/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION:C/a[0-9]$//}/
