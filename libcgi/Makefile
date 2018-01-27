# $NetBSD: Makefile,v 1.1 2013/03/08 12:36:39 makoto Exp $
DISTNAME=	libcgi-1.0
CATEGORIES=	www
MASTER_SITES=	http://prdownloads.sourceforge.net/libcgi/
LICENSE=	generic-nonlicense

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcgi.sourceforge.net/
COMMENT=	Library for authoring cgi

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		dst
SUBST_MESSAGE.dst=	Adding DESTDIR on top of install target
SUBST_FILES.dst=	Makefile.in
SUBST_SED.dst=		-e 's|@@DESTDIR@@|${DESTDIR}|g'
SUBST_STAGE.dst=	pre-configure

SUBST_CLASSES+=		libtool
SUBST_MESSAGE.libtool=	Let examples libtoolize

SUBST_FILES.libtool+=	examples/guestbook/Makefile
SUBST_FILES.libtool+=	examples/multiple/Makefile
SUBST_FILES.libtool+=	examples/redirect/Makefile
SUBST_FILES.libtool+=	examples/session/session_ex1/Makefile
SUBST_FILES.libtool+=	examples/session/session_ex2/Makefile
SUBST_FILES.libtool+=	examples/simple_form/Makefile
SUBST_FILES.libtool+=	examples/strings/Makefile

SUBST_STAGE.libtool=	post-patch
SUBST_SED.libtool=	-e 's|@@PREFIX@@|${PREFIX}|g'

do-install:
	${MKDIR} ${DESTDIR}${PKGMANDIR}/man3
	(cd ${WRKSRC}; \
	${GMAKE} install; \
	${GMAKE} install_man )

.include "../../mk/bsd.pkg.mk"
