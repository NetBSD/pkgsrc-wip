# $NetBSD: Makefile,v 1.42 2019/06/18 12:36:59 gdt Exp $

VERSION=	1.32.3
PKGREVISION=	9
# Distfile is ZoneMinder but package and tarball contents are zoneminder.
NAME_DIST=	ZoneMinder
NAME_LOWER=	zoneminder

PKGNAME=	${DISTNAME:S/${NAME_DIST}-/${NAME_LOWER}-/}
DISTNAME=	${NAME_DIST}-${VERSION}
WRKSRC=		${WRKDIR}/${NAME_LOWER}-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=${NAME_DIST}/}
GITHUB_PROJECT=	${NAME_DIST}
GITHUB_TYPE=	tag
GITHUB_TAG=	${PKGVERSION_NOREV}

# Submodules as per ZoneMinder's .gitmodules file, except that crud is no longer
# at ZoneMinder so we use FriendsOfCake instead.
# \todo Consider 3.0 vs v3.0.10, as the .gitmodules points to 3.0.
GITHUB_SUBMODULES+=	FriendsOfCake crud v3.0.10 web/api/app/Plugin/Crud
GITHUB_SUBMODULES+=	ZoneMinder CakePHP-Enum-Behavior master web/api/app/Plugin/CakePHP-Enum-Behavior

MAINTAINER=	dsainty@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://www.zoneminder.com/
COMMENT=	Video camera security and surveillance solution
LICENSE=	gnu-gpl-v2

# ZoneMinder without a web server does not really make sense, and if
# it did, what is omitted is surely not right.  For now, require a
# choice of webserver.
PKG_OPTIONS_VAR=		PKG_OPTIONS.zoneminder
PKG_OPTIONS_REQUIRED_GROUPS=	webserver
PKG_OPTIONS_GROUP.webserver=	apache nginx
PKG_SUGGESTED_OPTIONS=		apache

.include "../../mk/bsd.options.mk"

## MAIN BUILD

# As of 1.32, ZoneMinder has removed autoconf support.
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl pkg-config

# For now, lean to debugging.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=true
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

## PATHS

# zoneminder has a dizzying array of variables for various paths.
# Consolidate the settings in an attempt to reduce confusion.

# ZoneMinder prefers a subdirectory of etc. Further, it demands a
# conf.d subdirectory within its config directory, which would be
# irregular at top level.
CMAKE_CONFIGURE_ARGS+=		-DZM_CONFIG_DIR=${PKG_SYSCONFDIR}/zm
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/zm/conf.d ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# \todo We prepare a webroot, even without the apache option.
ZM_HTTPD_ROOT=		share/zoneminder/htdocs
CMAKE_CONFIGURE_ARGS+=		-DZM_WEBDIR=${PREFIX}/${ZM_HTTPD_ROOT:Q}
PLIST_SUBST+=		ZM_HTTPD_ROOT=${ZM_HTTPD_ROOT:Q}
PRINT_PLIST_AWK+=	{ gsub(/${ZM_HTTPD_ROOT:S|/|\\/|g}/, "$${ZM_HTTPD_ROOT}") }
OWN_DIRS+=		${ZM_HTTPD_ROOT:Q}
INSTALLATION_DIRS+=	share/zoneminder ${ZM_HTTPD_ROOT}

ZM_HTTPD_CGIBIN=	libexec/zoneminder/cgi-bin
CMAKE_CONFIGURE_ARGS+=		-DZM_CGIDIR=${PREFIX}/${ZM_HTTPD_CGIBIN:Q}
PLIST_SUBST+=		ZM_HTTPD_CGIBIN=${ZM_HTTPD_CGIBIN:Q}
PRINT_PLIST_AWK+=	{ gsub(/${ZM_HTTPD_CGIBIN:S|/|\\/|g}/, "$${ZM_HTTPD_CGIBIN}") }
BUILD_DEFS+=		ZM_HTTPD_CGIBIN
OWN_DIRS+=		${ZM_HTTPD_CGIBIN:Q}
INSTALLATION_DIRS+=	libexec/zoneminder ${ZM_HTTPD_CGIBIN}

BUILD_DEFS+=		VARBASE
CMAKE_CONFIGURE_ARGS+=		-DZM_RUNDIR=${VARBASE}/run/zm
# \todo Consider a way to clean up on de-install as anything left
# should just be removed.
OWN_DIRS_PERMS+=	${VARBASE}/run/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# NB: Startup script must create /var/run/zm.
CMAKE_CONFIGURE_ARGS+=		-DZM_SOCKDIR=${VARBASE}/run/zm
# Choose /var/tmp for now.  \todo Revisit.
CMAKE_CONFIGURE_ARGS+=		-DZM_TMPDIR=${VARBASE}/tmp/zm
OWN_DIRS_PERMS+=	${VARBASE}/tmp/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775
CMAKE_CONFIGURE_ARGS+=		-DZM_LOGDIR=${VARBASE}/log/zm
OWN_DIRS_PERMS+=	${VARBASE}/log/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# \todo Define this per-OS; /var/shm is for NetBSD
ZM_SHM=			/var/shm
CMAKE_CONFIGURE_ARGS+=		-DZM_PATH_MAP=${ZM_SHM}

# Cache directory is for js files to be served.  For now, use
# /var/cache/zoneminder.  \todo Consider /tmp/zm instead.
ZM_CACHE=		${VARBASE}/cache/zoneminder
CMAKE_CONFIGURE_ARGS+=		-DZM_CACHEDIR=${ZM_CACHE}
OWN_DIRS_PERMS+=	${ZM_CACHE} ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# Storage of events; this should persist and is hence in /var/db.
# \todo Understand how and why /images is used.
ZM_CONTENT=		${VARBASE}/db/zoneminder
CMAKE_CONFIGURE_ARGS+=		-DZM_CONTENTDIR=${ZM_CONTENT}
OWN_DIRS_PERMS+=	${ZM_CONTENT} ${REAL_ROOT_USER} ${APACHE_GROUP} 775
CMAKE_CONFIGURE_ARGS+=		-DZM_DIR_EVENTS=${ZM_CONTENT}/events
OWN_DIRS_PERMS+=	${ZM_CONTENT}/events ${APACHE_USER} ${APACHE_GROUP} 775
CMAKE_CONFIGURE_ARGS+=		-DZM_DIR_IMAGES=${ZM_CONTENT}/images
OWN_DIRS_PERMS+=	${ZM_CONTENT}/images ${APACHE_USER} ${APACHE_GROUP} 775

## Dependencies other than perl and php.

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

# This should probably be ffmpeg4 at least.
# \todo Try higher versions with 1.32.
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif
.for lib in AVFORMAT AVCODEC AVDEVICE AVUTIL SWSCALE
CMAKE_CONFIGURE_ARGS+=	-D${lib}_INCLUDE_DIR=${BUILDLINK_PREFIX.ffmpeg2}/include/ffmpeg2
CMAKE_CONFIGURE_ARGS+=	-D${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg2}/lib/ffmpeg2/lib${lib:tl}.${SOEXT}
.endfor
# This is somewhat awkward.  ffmpeg's libavformat/avformat.h requires
# constant macros from stdint.h, but these are only defined under C++ if
# __STDC_CONSTANT_MACROS is requested, so we have to do that on behalf
# of ffmpeg.  Failure to do so causes configure time failures, and
# build failures complaining about UINT64_T not being defined.
CFLAGS+=		-D__STDC_CONSTANT_MACROS

# MySQL uses openssl.  Force zoneminder not to choose otherwise by
# finding libraries that are present but not buildlinked.
CMAKE_CONFIGURE_ARGS+=		-DGNUTLS_LIBRARIES=""
CMAKE_CONFIGURE_ARGS+=		-DGCRYPT_LIBRARIES=""

# Darwin does have sendfile(), but the API differs from ZoneMinder's
# expectation.
# \todo Convert to cmake.
# CONFIGURE_ARGS.Darwin+=	ac_cv_func_sendfile=no ac_cv_header_sys_sendfile_h=no

# \todo After finding execinfo.h, cmake looks for and fails to find
# "backtrace".
# \todo Explain why we don't just depend on devel/libexecinfo.
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=		-lexecinfo
.endif

## PERL

PERL5_REQD+=		5.6.0

# \todo Thoroughly review and rototill this section. 
#
# Arrange for module.mk to perform its magic here on top of the non-Perl
# build tasks.
#
# Set ZM_PERL_MM_PARMS in order to inhibit NO_PACKLIST
#
#PERL5_CONFIGURE=	no
#PERL5_CONFIGURE_DIRS=	${WRKSRC}/scripts/ZoneMinder
#PERL5_CONFIGURE_DIRS+=	${WRKSRC}/onvif/proxy
#PERL5_CONFIGURE_DIRS+=	${WRKSRC}/onvif/modules
#PERL5_PACKLIST=	auto/ZoneMinder/.packlist
#PERL5_PACKLIST+=	auto/ONVIF/.packlist
#CMAKE_CONFIGURE_ARGS+=		-DZM_PERL_MM_PARMS="INSTALLDIRS=vendor"
#.include "../../lang/perl5/module.mk"

# ZoneMinder discourages building from source and does not appear to
# document the list of dependencies.  We take the view that if an
# installation can be reasonably configured to use a module, that
# module should be a dependency, absent some reason that it is so
# heavyweight that it should be an option.
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Device-SerialPort-[0-9]*:../../comms/p5-Device-SerialPort
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
DEPENDS+=	p5-Class-Std-Fast-[0-9]*:../../devel/p5-Class-Std-Fast
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
DEPENDS+=	p5-Sys-Mmap-[0-9]*:../../devel/p5-Sys-Mmap
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-IO-Socket-Multicast-[0-9]*:../../net/p5-IO-Socket-Multicast
DEPENDS+=	p5-Net-SFTP-Foreign-[0-9]*:../../net/p5-Net-SFTP-Foreign
DEPENDS+=	p5-SOAP-WSDL-[0-9]*:../../net/p5-SOAP-WSDL
DEPENDS+=	p5-Sys-MemInfo-[0-9]*:../../sysutils/p5-Sys-MemInfo
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Number-Bytes-Human-[0-9]*:../../textproc/p5-Number-Bytes-Human
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

# All perl scripts need interpreter patching (REPLACE_PERL), while a large
# subset also need an include PATH line modified (ZM_REPLACE_PERL).
ZM_REPLACE_PERL+=	scripts/zmaudit.pl.in
ZM_REPLACE_PERL+=	scripts/zmcamtool.pl.in
ZM_REPLACE_PERL+=	scripts/zmcontrol.pl.in
ZM_REPLACE_PERL+=	scripts/zmdc.pl.in
ZM_REPLACE_PERL+=	scripts/zmfilter.pl.in
REPLACE_PERL+=		scripts/zmonvif-probe.pl.in
ZM_REPLACE_PERL+=	scripts/zmpkg.pl.in
ZM_REPLACE_PERL+=	scripts/zmstats.pl.in
REPLACE_PERL+=		scripts/zmsystemctl.pl.in
ZM_REPLACE_PERL+=	scripts/zmtelemetry.pl.in
ZM_REPLACE_PERL+=	scripts/zmtrack.pl.in
ZM_REPLACE_PERL+=	scripts/zmtrigger.pl.in
ZM_REPLACE_PERL+=	scripts/zmupdate.pl.in
ZM_REPLACE_PERL+=	scripts/zmvideo.pl.in
ZM_REPLACE_PERL+=	scripts/zmwatch.pl.in
ZM_REPLACE_PERL+=	scripts/zmx10.pl.in
REPLACE_PERL+=	${ZM_REPLACE_PERL}

# The intention of zmsystemctl.pl is to use bin/pkexec to allow the
# apache user to start and stop the ZoneMinder services on operating
# systems using systemd and adequately recent Polkit.  Rather than
# trying to express dependencies, we just let it be and hope that it
# will work in environments where it can.  In other environments, we
# hope that no one runs the command.
CHECK_INTERPRETER_SKIP+=	bin/zmsystemctl.pl

# \todo Why isn't this just REPLACE_PERL?
SUBST_CLASSES+=			systemd-perl
SUBST_MESSAGE.systemd-perl=	Adjusting systemd pkexec perl.
SUBST_STAGE.systemd-perl=	pre-configure
SUBST_FILES.systemd-perl=	scripts/zmsystemctl.pl.in
SUBST_SED.systemd-perl=		-e 's|/usr/bin/perl|${PERL5}|g'

## PHP

# ZoneMinder 1.32 with PHP 7.4 does not appear to have PHP-related problems.
# Under PHP 8.0 <1.30 was logging at Error level type errors out of skin.js.
# Under PHP 8.1 <1.30 was logging at Panic level that strftime is deprecated.
#
# Therefore 74 is the standard approach and it is \todo to try higher.
PHP_VERSIONS_ACCEPTED=	74

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-apcu-[0-9]*:../../www/php-apcu

## WEB

# \todo We need to choose user/group, and somehow make this play well
# with apache, nginx, and php_fpm.  For now, assume that anyone using
# nginx/fpm will align that to APACHE_*, and treat the larger question
# as beyond scope.
PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

CMAKE_CONFIGURE_ARGS+=		-DZM_WEB_USER=${APACHE_USER}
CMAKE_CONFIGURE_ARGS+=		-DZM_WEB_GROUP=${APACHE_GROUP}
CMAKE_CONFIGURE_ARGS+=		-DZM_PATH_ZMS=zm/cgi-bin/nph-zms

.if !empty(PKG_OPTIONS:Mapache)
.include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-[0-9]*:../../www/ap-php
.endif
.if !empty(PKG_OPTIONS:Mnginx)
# \todo Actually test this option.
DEPENDS+=	nginx-[0-9]*:../../www/nginx
DEPENDS+=	${PHP_PKG_PREFIX}-fpm-[0-9]*:../../www/php-fpm
.endif

## PATH FIXUPS

# Patch the db creation script so that default paths installed in the
# db match how we have configured the package.
SUBST_CLASSES+=			dbpaths-path
SUBST_MESSAGE.dbpaths-path=	Adjusting default paths in configuration.
SUBST_STAGE.dbpaths-path=	pre-configure
SUBST_FILES.dbpaths-path=	db/zm_create.sql.in
SUBST_SED.dbpaths-path=		-e 's|/usr/local/bin/|${PREFIX}/bin/|g'
SUBST_SED.dbpaths-path+=	-e 's|/usr/bin|${PREFIX}/bin|g'
SUBST_SED.dbpaths-path+=	-e 's|/cgi-bin/nph-zms|/zm/cgi-bin/nph-zms|g'

# In most perl scripts, set the path to include $prefix/bin, rather
# than looking in /usr/local/bin, so that mysql, sudo, and so on are
# found.  (Scripts are in ZM_REPLACE_PERL rather than just
# REPLACE_PERL if they should get this substitution.)
SUBST_CLASSES+=			script-path
SUBST_MESSAGE.script-path=	Adjusting paths in scripts.
SUBST_STAGE.script-path=	pre-configure
SUBST_FILES.script-path=	${ZM_REPLACE_PERL}
SUBST_SED.script-path=		-e "s|^\\([\$$]ENV{PATH} *= *'\\).*';\$$|\\1${PREFIX}/bin:/bin:/usr/bin';|g"

# Substitute configured path in pkgsrc-provided apache config.
SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	httpd-zoneminder.conf
SUBST_SED.files=	-e "s|@ZM_HTTPD_ROOT@|${PREFIX}/${ZM_HTTPD_ROOT}|g"
SUBST_SED.files+=	-e "s|@ZM_HTTPD_CGIBIN@|${PREFIX}/${ZM_HTTPD_CGIBIN}|g"
SUBST_MESSAGE.files=	Fixing ZoneMinder configuration file for Apache.

## INIT SCRIPTS

# \todo Figure out if this is really for pkgsrc rc.d, and maybe write one for
# files/

PLIST_VARS+=		rcd

.if ${INIT_SYSTEM} == "rc.d"
PLIST.rcd=		yes
# \todo fix
#RCD_SCRIPTS+=		zoneminder
.endif
PRINT_PLIST_AWK+=	{ gsub(/^.+\/examples\/rc.d/, "$${PLIST.rcd}&"); }

## PKGSRC PHASE FIXUPS

# Pretend our apache config is part of the distribution.
# Avoid conflict with C++20 <version> - intertwined with patch-CMakeLists.txt
post-extract:
	${CP} ${FILESDIR}/httpd-zoneminder.conf ${WRKSRC}/httpd-zoneminder.conf
	${MV} ${WRKSRC}/version ${WRKSRC}/version.txt

# Omit patchfiles from PLIST if present.  The pre-configure step below
# should prevent this from being necessary.
PRINT_PLIST_AWK+=	/.orig$$/ { next; }

# After patching, remove .orig versions of .pm, because they are
# wrongly installed due to wildcard rules.
pre-configure:
	${FIND} ${WRKSRC} -name "*.pm*.orig" -type f | ${XARGS} ${RM} -f


# \todo Review if the cmake build now supports installation.
# \todo Document the symlink game with ZM_CONTENT.
EGDIR=			share/examples/${PKGBASE}
DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/config ${EGDIR}/apache
CONF_FILES+=		${PREFIX}/${EGDIR}/config/zm.conf ${PKG_SYSCONFDIR}/zm/zm.conf
INSTALLATION_DIRS+=	bin share/examples/rc.d share/zoneminder/db
INSTALLATION_DIRS+=	${DOCDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/httpd-zoneminder.conf ${DESTDIR}${PREFIX}/${EGDIR}/apache/httpd-zoneminder.conf
	${INSTALL_DATA} ${WRKSRC}/zm.conf ${DESTDIR}${PREFIX}/${EGDIR}/config/zm.conf
.if ${INIT_SYSTEM} == "rc.d"
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/zm ${DESTDIR}${PREFIX}/share/examples/rc.d/zoneminder
.endif
	${INSTALL_DATA} ${WRKSRC}/db/*.sql ${DESTDIR}${PREFIX}/share/zoneminder/db/
	${INSTALL_DATA} files/README-pkgsrc.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
# \todo Consider graphics/libv4l.
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/mp4v2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
