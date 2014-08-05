# $NetBSD: Makefile,v 1.1 2014/08/05 05:37:59 makoto Exp $
DISTNAME=	mailutils-2.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gnu.org/gnu/mailutils
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailutils.org/
COMMENT=	Command line mail utils (for OS missing ucbmail)

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
