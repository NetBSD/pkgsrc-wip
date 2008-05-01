# $NetBSD: Makefile,v 1.1.1.1 2008/05/01 16:14:32 koifren Exp $

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

do-install:
	${INSTALL} ${WRKSRC}/build/mwf-designer.exe ${PREFIX}/bin

.include "../../wip/mk/svn-package.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
