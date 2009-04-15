# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 21:17:17 zecrazytux Exp $

DISTNAME=					pandoc-1.2
CATEGORIES=				textproc
MASTER_SITES=			http://pandoc.googlecode.com/files/

MAINTAINER=				zecrazytux@zecrazytux.net
HOMEPAGE=					http://johnmacfarlane.net/pandoc/
COMMENT=					Pandoc is a Haskell library to convert markups

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=				gmake sed

WRKSRC=						${WRKDIR}/pandoc-1.2
USE_LANGUAGES=		c

SUBST_CLASSES+=		makefile1 makefile2 makefile3

SUBST_MESSAGE.makefile1=		Fixing the Makefile.
SUBST_STAGE.makefile1=			pre-configure
SUBST_FILES.makefile1=			Makefile
SUBST_SED.makefile1=				-e 's,+a=x,-a=x,g'

SUBST_MESSAGE.makefile2=		Fixing the Makefile.
SUBST_STAGE.makefile2=			pre-configure
SUBST_FILES.makefile2=			Makefile
SUBST_SED.makefile2=				-e 's,$$(STRIP)\ $$(EXECS),$$(STRIP)\ $$(MAIN),g'

SUBST_MESSAGE.makefile3=		Fixing the Makefile.
SUBST_STAGE.makefile3=			pre-configure
SUBST_FILES.makefile3=			Makefile
SUBST_SED.makefile3=				-e 's,^MANPATH.*,MANPATH\ :=\ $$(DESTPATH)/man,g'


.include "../../wip/hs-zip-archive/buildlink3.mk"
.include "../../wip/hs-digest/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../wip/hs-binary/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
