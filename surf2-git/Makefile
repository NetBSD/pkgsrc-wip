# $NetBSD: Makefile,v 1.6 2015/07/13 11:10:36 leot1990 Exp $

DISTNAME=	surf2-2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://surf.suckless.org/
COMMENT=	Fast and minimalistic web browser based on WebKit/GTK+
LICENSE=	mit

GIT_REPO=	http://git.suckless.org/surf

USE_TOOLS+=	pkg-config
MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Fixing config.mk
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.configmk+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

# Install binary and man page as surf2 to avoid conflicts with wip/surf
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/surf ${DESTDIR}${PREFIX}/bin/surf2
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/surf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/surf2.1

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/gcr/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
