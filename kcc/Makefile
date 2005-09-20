# $NetBSD: Makefile,v 1.1.1.1 2005/09/20 12:12:41 obache Exp $

DISTNAME=	kcc
PKGNAME=	kcc-1.0
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_FREEBSD} \
		ftp://ftp.sra.co.jp/pub/os/linux/JE/sources/base/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	# empty
COMMENT=	Kanji code converter with auto encoding detection

MAKE_FLAGS+=	BINPATH=${PREFIX}/bin
MAKE_FLAGS+=	MANPATH=${PREFIX}/man
MAKE_FLAGS+=	JMANDIR=ja_JP.EUC

INSTALL_TARGET=	install install.man

.include "../../mk/bsd.pkg.mk"
