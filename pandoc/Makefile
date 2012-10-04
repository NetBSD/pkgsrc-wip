# $NetBSD: Makefile,v 1.4 2012/10/04 19:44:06 asau Exp $

DISTNAME=					pandoc-1.2
PKGREVISION=				1
CATEGORIES=				textproc
MASTER_SITES=			http://pandoc.googlecode.com/files/

MAINTAINER=				zecrazytux@zecrazytux.net
HOMEPAGE=					http://johnmacfarlane.net/pandoc/
COMMENT=					Pandoc is a Haskell library to convert markups

USE_TOOLS+=				gmake sed

WRKSRC=						${WRKDIR}/pandoc-1.2
USE_LANGUAGES=		c

SUBST_CLASSES+=		makefile

SUBST_MESSAGE.makefile=		Fixing the Makefile.
SUBST_STAGE.makefile=			pre-configure
SUBST_FILES.makefile=			Makefile
SUBST_SED.makefile=				-e 's,+a=x,-a=x,g'
SUBST_SED.makefile+=			-e 's,$$(STRIP)\ $$(EXECS),$$(STRIP)\ $$(MAIN),g'
SUBST_SED.makefile+=			-e 's,^MANPATH.*,MANPATH\ :=\ $$(DESTPATH)/man,g'

.include "../../wip/hs-zip-archive/buildlink3.mk"
.include "../../wip/hs-digest/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../wip/hs-binary/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
