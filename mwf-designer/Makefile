# $NetBSD: Makefile,v 1.3 2008/10/12 14:36:09 koifren Exp $

DISTNAME=	mwf-designer
PKGNAME=	${DISTNAME}-${MWF_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.mono-project.com/

.include "../../mk/bsd.prefs.mk"
MWF_VERSION!=	${DATE} +%Y%m%d

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Managed Windows Forms Designer

SVN_REPOSITORIES=	mono
SVN_ROOT.mono=		svn://anonsvn.mono-project.com/source/trunk/mwf-designer
SVN_MODULE.mono=	${DISTNAME}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-install
SUBST_MESSAGE.fix-prefix=	Fixing prefix directory.
SUBST_FILES.fix-prefix=		mwf-designer
SUBST_SED.fix-prefix=		-e "s,%PREFIX%,${PREFIX},g"

do-install:
	${INSTALL} ${WRKSRC}/build/mwf-designer.exe ${PREFIX}/bin
	${INSTALL} ${WRKSRC}/deps/ICSharpCode.NRefactory.dll ${PREFIX}/lib/mono/2.0
	${INSTALL} ${WRKSRC}/mwf-designer ${PREFIX}/bin

.include "../../wip/mk/svn-package.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
