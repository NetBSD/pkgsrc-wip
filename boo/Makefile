# $NetBSD: Makefile,v 1.2 2013/06/17 12:45:10 thomasklausner Exp $
#

DISTNAME=	boo-0.9.4.9-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://dist.codehaus.org/boo/distributions/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://boo.codehaus.org/
COMMENT=	Wrist friendly language for the CLI
LICENSE=	modified-bsd # ?

BUILD_DEPENDS+=	nant-[0-9]*:../../devel/nant

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	aclocal autoconf autoheader automake pkg-config
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	extras/boo.pc.in

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	default.build
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${DESTDIR}${PREFIX}|1"
SUBST_STAGE.prefix=	post-extract

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} nant

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} nant install

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
