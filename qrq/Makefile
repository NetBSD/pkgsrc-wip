# $NetBSD: Makefile,v 1.1.1.1 2011/07/28 12:34:58 ryo-on Exp $
#

DISTNAME=	qrq-0.2.0
CATEGORIES=	ham
MASTER_SITES=	http://fkurz.net/ham/qrq/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fkurz.net/ham/qrq.html
COMMENT=	Open source Morse telegraphy trainer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run

REPLACE_PERL=	qrqscore

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_MESSAGE.destdir=	Fixing prefix.
SUBST_FILES.destdir=	Makefile
SUBST_SED.destdir=	-e 's,/usr,${PREFIX},'

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_SED.pthread+=	-e 's/-lpthread/${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}/g'

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
