# $NetBSD: Makefile,v 1.49 2020/08/31 18:10:28 wiz Exp $

DISTNAME=	gstreamer-1.18.3
PKGNAME=	${DISTNAME:S/gstreamer/gstreamer1/}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		bison flex perl pkg-config
TEST_TARGET=		check
FLEX_REQD=		2.5.31

.include "options.mk"

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base.pc.in

CHECK_PORTABILITY_SKIP+=	hooks/pre-commit.hook

REPLACE_PYTHON+=	gst/parse/get_flex_version.py
REPLACE_PYTHON+=	docs/gst-plugins-doc-cache-generator.py
REPLACE_PYTHON+=	gst/parse/gen_grammar.py.in
REPLACE_PYTHON+=	gst/parse/gen_lex.py.in
REPLACE_PYTHON+=	scripts/dist-translations.py
REPLACE_PYTHON+=	scripts/extract-release-date-from-doap-file.py
REPLACE_PYTHON+=	output/gst/parse/gen_lex.py
REPLACE_PYTHON+=	output/gst/parse/gen_grammar.py
REPLACE_PYTHON+=	output/docs/gst-plugins-doc-cache-generator

.include "../../lang/python/application.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
