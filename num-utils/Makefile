# $NetBSD$

DISTNAME=	num-utils-0.5
CATEGORIES=	textproc
MASTER_SITES=	http://suso.suso.org/programs/num-utils/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://suso.suso.org/programs/num-utils/downloads/
COMMENT=	Set of programs that deals with numbers
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake perl

REPLACE_PERL+=	average bound interval normalize numgrep numprocess numsum random range round

MAKE_FLAGS+=	TOPDIR=${DESTDIR}/${PREFIX}
MAKE_FLAGS+=	MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

SUBST_CLASSES+=			fix-perms
SUBST_STAGE.fix-perms=		pre-configure
SUBST_MESSAGE.fix-perms=	Fixing uid/gid of files
SUBST_FILES.fix-perms+=		Makefile
SUBST_SED.fix-perms+=		-e 's,-o 0 -g 0,,g'

.include "../../mk/bsd.pkg.mk"
