# $NetBSD: Makefile,v 1.3 2015/06/03 22:54:02 krytarowski Exp $

DISTNAME=	enigmail-1.8.2
PKGNAME=	thunderbird-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.mozilla-enigmail.org/download/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.enigmail.net/
COMMENT=	GnuPG support for mail/thunderbird
LICENSE=	(mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1) AND mpl-2.0

USE_TOOLS+=	gmake perl sed unzip

# It doesn't work -- noted also here:
# https://aur.archlinux.org/packages/th/thunderbird-enigmail/PKGBUILD
MAKE_JOBS_SAFE=	no

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		thunderbird>=31:../../mail/thunderbird
DEPENDS+=		gnupg-[0-9]*:../../security/gnupg

REPLACE_PERL+=	config/getOsTarget.pl
REPLACE_PERL+=	util/fixlang.pl
REPLACE_PERL+=	util/make-lang-xpi.pl

REPLACE_PYTHON+=	util/checkFiles.py
REPLACE_PYTHON+=	util/header.py
REPLACE_PYTHON+=	util/typelib.py
REPLACE_PYTHON+=	util/header.py
REPLACE_PYTHON+=	util/xpidl.py
REPLACE_PYTHON+=	util/xpt.py

WRKSRC=		${WRKDIR}/enigmail
GNU_CONFIGURE=	yes

XPIVER=		${PKGVERSION_NOREV:C/.[0-9]+$//}
ENIGMAILXPI=	enigmail-${XPIVER}-${LOWER_OPSYS}-${MACHINE_GNU_ARCH}-gcc3.xpi
XPIFILE=	${WRKSRC}/build/${ENIGMAILXPI}
XPIDIR=		${PREFIX}/lib/thunderbird/extensions

# Build instructions: https://www.enigmail.net/download/build_instructions.php
# Installation of extensions: http://kb.mozillazine.org/Installing_extensions
# Model installation: https://aur.archlinux.org/packages/th/thunderbird-enigmail/PKGBUILD
do-install:
	${RUN} EMID=`${SED} -n '/.*<em:id>\\(.*\\)<\\/em:id>.*/{s//\\1/p;q}' \
		${WRKSRC}/package/install.rdf` && \
		${INSTALL_DATA_DIR} ${DESTDIR}${XPIDIR}/"$$EMID" && \
		unzip -d ${DESTDIR}${XPIDIR}/"$$EMID" \
		${XPIFILE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
