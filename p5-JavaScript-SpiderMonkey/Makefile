# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:30 asau Exp $
#

DISTNAME=	JavaScript-SpiderMonkey-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JavaScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JavaScript/SpiderMonkey/
COMMENT=	Perl interface to the JavaScript Engine


MAKE_PARAMS+=	INC=${PREFIX}/include

SUBST_CLASSES+=		fix-lib
SUBST_STAGE.fix-lib=	pre-configure
SUBST_MESSAGE.fix-lib=	Fixing library detection
SUBST_FILES.fix-lib=	Makefile.PL
SUBST_SED.fix-lib=	-e 's,libmozjs.so,libjs.so,g'
SUBST_SED.fix-lib+=	-e 's,/usr/local,${PREFIX},g'

PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
MAKE_PARAMS+=	-JS_THREADSAFE
.endif

PERL5_PACKLIST=	auto/JavaScript/SpiderMonkey/.packlist

.include "options.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
