# $NetBSD: Makefile,v 1.8 2012/12/04 00:04:07 othyro Exp $
#

DISTNAME=	drow-0.2.22
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=drow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drow.sourceforge.net/
COMMENT=	Low-level ELF file analyzer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

CONFIGURE_ENV+=		DESTDIR=${DESTDIR}
INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
