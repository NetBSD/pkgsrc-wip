# $NetBSD: Makefile,v 1.9 2013/01/10 14:50:15 othyro Exp $
#

DISTNAME=	drow-0.2.22
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=drow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drow.sourceforge.net/
COMMENT=	Low-level ELF file analyzer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

PKG_DESTDIR_SUPPORT=	destdir
CONFIGURE_ENV+=		DESTDIR=${DESTDIR}
INSTALLATION_DIRS+=	bin

SPECIAL_PERMS+=		bin/drow bin bin 0755

.include "../../mk/bsd.pkg.mk"
