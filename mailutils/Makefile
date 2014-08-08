# $NetBSD: Makefile,v 1.2 2014/08/08 12:20:06 makoto Exp $
DISTNAME=	mailutils-2.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gnu.org/gnu/mailutils/
#MASTER_SITES=	http://ftp.gnu.org/gnu/mailutils/
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
