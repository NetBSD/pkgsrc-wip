# $NetBSD: Makefile,v 1.24 2019/04/26 14:12:35 maya Exp $

DISTNAME=	weewx-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	misc
MASTER_SITES=	http://weewx.com/downloads/

# See also
# https://reviews.freebsd.org/file/data/wxlggqqqglli6l66usac/PHID-FILE-kucs3bj4stbb6iw4zpy5/D6324.diff

# Do not make this package installable; email me if questions.
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://weewx.com/
COMMENT=	Python-powered template engine and code-generator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=

# \todo Allow python 3
PYTHON_VERSIONS_ACCEPTED=	27 # not yet tested

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Substituting pkgsrc paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	setup.cfg
SUBST_VARS.paths=	PREFIX

# These versions are probably higher than necessary, but there is little value
# in testing with versions older than are in pkgsrc.
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=2.7.16:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cheetah>=2.4.4:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-configobj>=5.0.6:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.6.0:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-usb>=1.0.0:../../devel/py-usb

# \todo Decide whether to depend/patch, omit, or continue to ignore.
CHECK_INTERPRETER_SKIP+=	weewx/util/init.d/weewx.lsb
CHECK_INTERPRETER_SKIP+=	weewx/util/init.d/weewx.suse
CHECK_INTERPRETER_SKIP+=	weewx/util/logwatch/scripts/services/weewx

# Move config file to an example-type path.
# \todo Consider patching setup.py instead.
post-install:
	mv ${DESTDIR}/${PREFIX}/weewx/weewx.conf ${DESTDIR}/${PREFIX}/weewx/weewx.conf.DIST

CONF_FILES+=	${PREFIX}/weewx/weewx.conf.DIST ${PREFIX}/weewx/weewx.conf

# weewx has its own scheme for updating the config file, and it is
# likely a lot of work to make a package that behaves correctly,
# separating out the code that runs at distutils install time into
# installation and configuration update.

# \todo Consider somehow integrating weewx's config file update scheme.

# \todo Consider how to manage edits to skins, which are sort of code
# and sort of config files.

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
