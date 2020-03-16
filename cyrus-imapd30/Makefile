# $NetBSD: $

DISTNAME=	cyrus-imapd-3.0.13
REVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=cyrusimap/}
GITHUB_RELEASE=	${PKGNAME_NOREV}

MAINTAINER=	mp@petermann-it.de
HOMEPAGE=	https://www.cyrusimap.org/
COMMENT=	Cyrus IMAP server
LICENSE=	original-bsd # like license
DEPENDS+=	p5-Term-ReadLine>=1.20:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Authen-SASL-Cyrus>=0.13:../../security/p5-Authen-SASL-Cyrus
DEPENDS+=	cyrus-saslauthd>=2.1.17:../../security/cyrus-saslauthd

MAKE_JOBS_SAFE=	no

USE_LANGUAGES+=	c c++
USE_TOOLS+=	perl:run makedepend yacc pkg-config sed awk gmake
USE_LIBTOOL=	yes

USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no

BUILD_DEFS+=		VARBASE

CHECK_PORTABILITY_SKIP=	configure.lineno

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER}
FILES_SUBST+=		CYRUS_GROUP=${CYRUS_GROUP}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/cyrus-master.pid
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

CONFIGURE_ARGS+=	--enable-idled
CONFIGURE_ARGS+=	--enable-murder
CONFIGURE_ARGS+=	--enable-nntp
CONFIGURE_ARGS+=	--enable-replication
CONFIGURE_ARGS+=	--htmldir=${DESTDIR}${HTMLDIR}

CONFIGURE_ARGS+=	andrew_cv_runpath_switch=${COMPILER_RPATH_FLAG}

.include "options.mk"

MAKE_ENV+=		PERL=${PERL5:Q}
MAKE_ENV+=		PERLLIBDIR=${PERL5_INSTALLVENDORLIB}

HTMLDIR=		${PREFIX}/share/doc/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${PKG_SYSCONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/cyrus.conf ${PKG_SYSCONFDIR}/cyrus.conf
RCD_SCRIPTS=		cyrus
FILES_SUBST+=		IMAPDCONF=${PKG_SYSCONFDIR}/imapd.conf

REPLACE_PERL+=		tools/rehash

pre-build:
	${RUN}${_ULIMIT_CMD}

.include "../../lang/perl5/module.mk"
BUILDLINK_API_DEPENDS.cyrus-sasl+=	cyrus-sasl>=2.1.17
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

# Only imap/mupdate needs to be build with pthreads support, so selectively
# enable it via patches for just that one program.
#
.include "../../mk/pthread.buildlink3.mk"

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.  Also change references to
# "/etc/{cyrus,imapd}.conf" into "${PKG_SYSCONFDIR}/{cyrus,imapd}.conf".
#
post-patch:
	cd ${WRKSRC}/man; \
	set --	deliver 8 fetchnews 8 idled 8 imapd 8 lmtpd 8 master 8 \
		nntpd 8 notifyd 8 pop3d 8 quota 8 httpd 8 httpdtest 8; \
	while [ $$# -gt 0 ]; do	\
		man=$$1.$$2; \
		for file in *.[0-9]; do \
			sed	-e "s|\(\$$(srcdir)/\)\($$man\)|\1cyrus-\2|g" \
				-e "s|\(\\\fB\)\($$1($$2)\\\fR\)|\1cyrus-\2|g" \
				$$file > $$file.fixed; \
			mv -f $$file.fixed $$file; \
		done; \
		if [ -f $$man ]; then \
			mv $$man cyrus-$$man; \
		fi; \
		for file in ../Makefile.in ../Makefile.am; do	\
			sed	-e "s|man/$$man|man/cyrus-$$man|g" \
				$$file > $$file.fixed; \
			mv -f $$file.fixed $$file; \
		done; \
		shift 2; \
	done
	find ${WRKSRC} -type f -print | \
	xargs -n 1 ${GREP} -l -e /etc/imapd\.conf -e /etc/cyrus\.conf | \
	while read file; do \
		sed	-e "s|/etc/\(cyrus\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			-e "s|/etc/\(imapd\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			$${file} > $${file}.fixed; \
		mv -f $${file}.fixed $${file}; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mknewsgroups ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/rehash ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/translatesieve ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/cyrus.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc/html; for directory in `find . -type d`; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}/$${directory}; \
	done
	cd ${WRKSRC}/doc/html; for file in `find . -type f \\( -iname \\*.html -o -iname \\*.jpg -o -iname \\*.png -o -iname \\*.css -o -iname \\*.js -o -iname \\*.json \\)`; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${HTMLDIR}/$${file}; \
	done

.include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
