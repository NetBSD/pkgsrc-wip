# $NetBSD: Makefile,v 1.4 2020/03/10 22:10:24 wiz Exp $

DISTNAME=	gjs-1.64.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gjs/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/Gjs
COMMENT=	Javascript binding for GNOME based on Spidermonkey
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gjs@sha:${WRKSRC}/output/gjs-jsapi@sta:${WRKSRC}/output/gjs-console@exe
MESON_ARGS+=	-Dinstalled_tests=false

PKGCONFIG_OVERRIDE+=		output/meson-private/gjs-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

# Needed by the Javascript JIT used in gjs
NOT_PAX_MPROTECT_SAFE+=	bin/gjs-console

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREPEND_PATH+=	${BUILDLINK_DIR}/bin

# override default target
.PHONY: meson-configure
meson-configure:
.  for d in ${CONFIGURE_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} ${BUILDLINK_DIR}/bin/python${PYVERSSUFFIX} meson \
		--prefix ${PREFIX} --libdir lib --mandir ${PKGMANDIR} \
		--sysconfdir ${PKG_SYSCONFDIR} --buildtype=plain ${MESON_ARGS} . output
.  endfor

pre-configure:
	cp ${PYTHONBIN} ${BUILDLINK_DIR}/bin/python${PYVERSSUFFIX}
	paxctl +m ${BUILDLINK_DIR}/bin/python${PYVERSSUFFIX}
	sed "s,${PYTHONBIN},${BUILDLINK_DIR}/bin/python${PYVERSSUFFIX}," ${PREFIX}/bin/g-ir-scanner > ${BUILDLINK_DIR}/bin/g-ir-scanner
	chmod 755 ${BUILDLINK_DIR}/bin/g-ir-scanner
	sed "s,.{bindir}/g-ir-scanner,${BUILDLINK_DIR}/bin/g-ir-scanner," ${BUILDLINK_DIR}/lib/pkgconfig/gobject-introspection-1.0.pc \
		> ${WRKDIR}/tmp.pc && ${RM} -f ${BUILDLINK_DIR}/lib/pkgconfig/gobject-introspection-1.0.pc && \
		mv ${WRKDIR}/tmp.pc ${BUILDLINK_DIR}/lib/pkgconfig/gobject-introspection-1.0.pc
	${LN} -sf ${PREFIX}/share/gir-1.0/*.* ${BUILDLINK_DIR}/share/gir-1.0/
	${LN} -sf ${PREFIX}/share/gobject-introspection-1.0/gdump.c ${BUILDLINK_DIR}/share/gobject-introspection-1.0/
#	echo '#!/bin/sh' > ${WRKSRC}/handle_pax
#	echo 'cp $$1 $$2' >> ${WRKSRC}/handle_pax
#	echo 'paxctl +m $$2' >> ${WRKSRC}/handle_pax
#	chmod 755 ${WRKSRC}/handle_pax
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/mozjs68/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
