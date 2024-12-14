# $NetBSD: Makefile,v 1.235 2024/11/17 07:16:21 wiz Exp $

DISTNAME=	evolution-data-server-3.54.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-data-server/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Evolution/
COMMENT=	Libraries and services for storing addressbooks and calendars
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl:run
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_TOOLS+=	gdbus-codegen
USE_LANGUAGES=	c c++

FORCE_CXX_STD=	c++17

CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBDB=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GOA=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WEATHER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_OAUTH2=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_OAUTH2_WEBKITGTK=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_OAUTH2_WEBKITGTK4=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_KRB5=${KRB5BASE}
CMAKE_CONFIGURE_ARGS+=	-DWITH_KRB5_INCLUDES=${KRB5BASE}/include/krb5

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/evolution-data-server

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	@PERL@ -w
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	src/tools/addressbook-export/csv2vcard.in

PKGCONFIG_OVERRIDE+=	evolution-data-server.pc.in
PKGCONFIG_OVERRIDE+=	src/addressbook/libebook-contacts/libebook-contacts.pc.in
PKGCONFIG_OVERRIDE+=	src/addressbook/libebook/libebook.pc.in
PKGCONFIG_OVERRIDE+=	src/addressbook/libedata-book/libedata-book.pc.in
PKGCONFIG_OVERRIDE+=	src/calendar/libecal/libecal.pc.in
PKGCONFIG_OVERRIDE+=	src/calendar/libedata-cal/libedata-cal.pc.in
PKGCONFIG_OVERRIDE+=	src/camel/camel.pc.in
PKGCONFIG_OVERRIDE+=	src/libebackend/libebackend.pc.in
PKGCONFIG_OVERRIDE+=	src/libedataserver/libedataserver.pc.in
PKGCONFIG_OVERRIDE+=	src/libedataserverui/libedataserverui.pc.in

# "gettext version 0.18.3+ required, but version '0.16.1' found instead."
#_TOOLS_USE_PKGSRC.msgfmt=	yes
#_TOOLS_USE_PKGSRC.msgmerge=	yes
#_TOOLS_USE_PKGSRC.xgettext=	yes

INSTALLATION_DIRS+=	share/examples
post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg \
		${DESTDIR}${PREFIX}/share/examples

CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.Evolution-alarm-notify.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.Evolution-alarm-notify.desktop

.include "../../devel/cmake/build.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../net/libgdata/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
