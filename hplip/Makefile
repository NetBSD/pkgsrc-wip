# $NetBSD: Makefile,v 1.8 2010/01/18 09:38:24 thomasklausner Exp $

DISTNAME=hplip-1.6.10
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hplip/}

MAINTAINER=	mwicks@kettering.edu
HOMEPAGE=	http://hplip.sourceforge.net/
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

PYTHON_PATCH_SCRIPTS=	./base/magic.py ./base/distros.py ./base/dcheck.py \
			./fax/backend/hpfax.py \
			./pcard/pcardext/setup.py \
			./prnt/cupsext/setup.py \
			./prnt/printable_areas.py \
			./scan/__init__.py \
			./makecopies.py ./align.py \
			./info.py ./print.py ./toolbox.py ./clean.py \
			./colorcal.py ./unload.py ./testpage.py \
			./makeuri.py \
			./check.py ./fab.py ./levels.py \
			./sendfax.py \
			./setup.py ./timedate.py ./probe.py \
			./hpssd.py ./install.py

REPLACE_PERL=		prnt/hpijs/foomatic-rip

PY_PATCHPLIST=		yes
FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP

EGDIR=			${LOCALBASE}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/hplip.conf ${PKG_SYSCONFDIR}/hplip.conf

#RCD_SCRIPTS=		hpiod hpssd
RCD_SCRIPTS=		hplip
PKG_USERS=		hplip:operator
PKG_GROUPS=		operator

CONFLICTS=	hpijs-[0-9]* foomatic-filters-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --sysconfdir=${EGDIR:Q} \
		--disable-dependency-tracking \
		--disable-pp-build

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"

post-extract:
	${RM} -r ${WRKSRC}/data/images/CVS

SUBST_CLASSES+=			fix-py-paths
SUBST_STAGE.fix-py-paths=	post-patch
SUBST_MESSAGE.fix-py-paths=	Fixing absolute paths in python files
SUBST_FILES.fix-py-paths=	base/*.py *.py ui/*.py prnt/*.py fax/backend/*.py
SUBST_SED.fix-py-paths=		-e 's,/etc/hp,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-py-paths+=	-e 's,/etc/cups,${PKG_SYSCONFDIR}/cups,g'
SUBST_SED.fix-py-paths+=	-e 's,/etc/sane.d,${PKG_SYSCONFDIR}/sane.d,g'
SUBST_SED.fix-py-paths+=	-e "s,'/usr/lib/cups,'${LOCALBASE}/libexec/cups,g"
SUBST_SED.fix-py-paths+=	-e "s,/usr/local,${LOCALBASE},g"

SUBST_CLASSES+=			fix-misc-paths
SUBST_STAGE.fix-misc-paths=	post-patch
SUBST_MESSAGE.fix-misc-paths=	Fixing absolute paths in miscellaneous files
SUBST_FILES.fix-misc-paths=	configure
SUBST_FILES.fix-misc-paths+=	prnt/hpijs/configure
SUBST_FILES.fix-misc-paths+=	prnt/hpijs/hplip_api.h
SUBST_FILES.fix-misc-paths+=	io/hpiod/hpiod.h
SUBST_FILES.fix-misc-paths+=	prnt/hpijs/foomatic-rip
SUBST_SED.fix-misc-paths=	-e 's,/usr/share/cups,${LOCALBASE}/share/cups,g'
SUBST_SED.fix-misc-paths=	-e 's,/usr/share/application,${LOCALBASE}/share/application,g'
SUBST_SED.fix-misc-paths+=	-e 's,/usr/lib/cups,${LOCALBASE}/libexec/cups,g'
SUBST_SED.fix-misc-paths+=	-e 's,/usr/local,${LOCALBASE},g'
SUBST_SED.fix-misc-paths+=	-e 's,"/etc/hp,"${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=			fix-make-paths
SUBST_STAGE.fix-make-paths=	post-patch
SUBST_MESSAGE.fix-make-paths=	Fixing absolute paths in Makefiles
SUBST_FILES.fix-make-paths=	Makefile.in prnt/hpijs/Makefile.in
SUBST_SED.fix-make-paths=	-e "s,install-data-am: install-docDATA,install-data-am:,g"
SUBST_SED.fix-make-paths+=	-e "s,install-dist_xmlDATA: install-docDATA,install-dist_xmlDATA:,g"

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${LN} -sf ${PREFIX}/share/hplip/hpssd.py ${PREFIX}/sbin/hpssd
	${LN} -sf ${PREFIX}/bin/foomatic-rip \
		${PREFIX}/libexec/cups/filter/foomatic-rip
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py ${PREFIX}/share/hplip

.include "../../mk/bsd.pkg.mk"
