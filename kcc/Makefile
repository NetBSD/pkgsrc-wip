# $NetBSD: Makefile,v 1.2 2006/02/11 15:56:37 obache Exp $

DISTNAME=	kcc
PKGNAME=	kcc-1.0
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_FREEBSD} \
		ftp://ftp.sra.co.jp/pub/os/linux/JE/sources/base/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	# empty
COMMENT=	Kanji code converter with auto encoding detection

MAKE_FLAGS+=	BINPATH=${PREFIX:Q}/bin
MAKE_FLAGS+=	MANPATH=${PREFIX:Q}/man
MAKE_FLAGS+=	JMANDIR=ja_JP.EUC

INSTALL_TARGET=	install install.man

.include "../../mk/bsd.pkg.mk"
