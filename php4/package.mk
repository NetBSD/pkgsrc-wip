# $NetBSD: package.mk,v 1.1.1.1 2003/09/01 12:49:55 adrian_p Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install pear packages.
#
# This is not linke a perl module in that you will need to generate
# a PLIST on your own and add it to your package.
#
# If you don't know what pair is you can visit: http://pear.php.net/
#
# PEAR_PREFIX	the directory under which pear packages are installed.
#		this will default to ${PREFIX}/lib/php
#
# PEAR_CMD	this is the actual script to execute to install the
#		package.
#

.if !defined(_PEAR_PACKAGE_MK)
_PEAR_PACKAGE_MK=       # defined

.include "../../www/php4/buildlink2.mk"
DEPENDS+=	php-zlib>4.3.0:../../archivers/php4-zlib

EXTRACT_SUFX=	.tgz

PEAR_PREFIX=	${PREFIX}/lib/php
PEAR_CMD=	${PREFIX}/bin/pear

#
# this does not belong here, it should be moved to bsd.pkg.mk when this
# file gets into the main pkgsrc tree.
#
MASTER_SITE_PAIR_PACKAGE+= \
	http://pear.php.net/get/

do-build:
	@${CP} ${WRKDIR}/package.xml ${WRKSRC}

do-install:
	@cd ${WRKSRC} && ${PEAR_CMD} install package.xml

.endif  # _PEAR_PACKAGE_MK
