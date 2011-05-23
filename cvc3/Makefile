# $NetBSD: Makefile,v 1.1 2011/05/23 19:05:26 marko_schuetz Exp $
#

DISTNAME=	cvc3-2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.nyu.edu/acsys/cvc3/releases/2.2/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.cs.nyu.edu/acsys/cvc3/releases/2.2/
COMMENT=	Automatic theorem prover for SMT problems

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake bash perl
PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=                 fix-bash
SUBST_STAGE.fix-bash=          	pre-configure
SUBST_MESSAGE.fix-bash=        	Fixing hard-coded reference to bash.
SUBST_FILES.fix-bash=          	Makefile.std
SUBST_SED.fix-bash=            	-e 's,SHELL = /bin/bash,SHELL = ${TOOLS_PATH.bash},g'

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
