# $NetBSD: Makefile,v 1.1 2012/11/02 05:11:51 othyro Exp $
#

DISTNAME=	jdksmidi-20121031-1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/downloads/jdkoftinoff/jdksmidi/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jdkoftinoff.com/main/Free_Projects/C++_MIDI_Library/
COMMENT=	C++ MIDI Library
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/jdkoftinoff-jdksmidi-3e342bd
USE_LANGUAGES=		c++
USE_TOOLS+=		bash gmake gtar
HAS_CONFIGURE=		yes
USE_LIBTOOL=		yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${BASH}
REPLACE_FILES.bash=	configure

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-install
SUBST_FILES.bash=	tmp-target/build/tools-dev/jdksmidi-config
SUBST_MESSAGE.bash=	Replacing bash interpreter in jdksmidi-config.
SUBST_SED.bash=		-e "s|/bin/bash|${BASH}|1"

INSTALL_ENV+=		TAR=${GTAR} TARGET_MAN_DIR=${PKGMANDIR}
INSTALL_ENV+=		TARGET_INSTALL_DEV_DIR=${DESTDIR}${PREFIX}


.include "../../mk/bsd.pkg.mk"
