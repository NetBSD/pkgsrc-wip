# $NetBSD$

GITHUB_PROJECT=	ledger
VERSION= 3.1
DISTNAME=	v${VERSION}
PKGNAME= ${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=ledger/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	http://ledger-cli.org/
COMMENT=	Double-entry accounting system for command-line
LICENSE=	modified-bsd

# url2pkg-marker (please do not remove this line.)

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${VERSION}
USE_LANGUAGES= c++ c
USE_TOOLS+= curl unzip

# A list of other things you need in order to configure and build using the Ledger acprep script, that I'm not sure where to put:
# - python
# - cmake

#Version 3.1 requires a separate download of UTFCPP, automate this
#With version 3.1.1 this should get bundled with the Ledger release and this target can be removed.
post-extract:
	cd ${WRKSRC} && curl -L -O https://github.com/ledger/ledger/releases/download/v3.1/ledger-utfcpp.zip && unzip ledger-utfcpp.zip

#This is a hack!
#The supplied acprep tool works really well for configuration and building, but in order to use it I had to disable the PKGSRC configure and build stages and then call acprep for configuration and build after the patch phase.
#See the TODO file for more details and everything less hacky I tried that didn't work.
NO_CONFIGURE= yes
NO_BUILD= yes
post-patch:
	cd ${WRKSRC} && ./acprep configure --prefix ${PREFIX} -- -DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON -DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR} && ./acprep make

.include "../../mk/bsd.pkg.mk"
.include "../../mk/fetch/sites.mk"

#These are the minimum libraries required for Ledger
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
