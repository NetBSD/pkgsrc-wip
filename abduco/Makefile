# $NetBSD: Makefile,v 1.14 2016/01/20 14:34:35 leot Exp $

DISTNAME=	abduco-0.6
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/abduco/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brain-dump.org/projects/abduco/
COMMENT=	Session {at,de}tach support
LICENSE=	isc

USE_LANGUAGES=		c99

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing config.mk
SUBST_FILES.config=	config.mk
SUBST_SED.config=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.config+=	-e 's,share/man,${PKGMANDIR},'
SUBST_SED.config+=	-e 's,^CPPFLAGS =,CPPFLAGS +=,'
SUBST_SED.config+=	-e 's,^CFLAGS =,CFLAGS +=,'
SUBST_SED.config+=	-e 's,^LDFLAGS =,LDFLAGS +=,'
SUBST_SED.config+=	-e 's/cc/${CC:Q}/'

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for VLNEXT in <sys/termios.h>

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
