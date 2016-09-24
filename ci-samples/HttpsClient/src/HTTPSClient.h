/*
 based on: http://stackoverflow.com/questions/22059026/connecting-to-an-https-server-with-boostasio
 */
//
//#pragma once
//
//#include "cinder/app/App.h"
//#include "asio/asio.hpp"
//#include "asio/ssl.hpp"
//
//using namespace ci;
//using namespace ci::app;
//using namespace std;
//using namespace asio;
//using namespace asio::ip;
//
//
//class HTTPSClient {
//
//public:
//
//
//	ssl::stream<ip::tcp::socket> *mSSLSocket;
//
//	HTTPSClient()
//	{
//		ssl::context context( ssl::context::sslv23 );
//		context.set_verify_mode(ssl::verify_peer);
//		context.set_default_verify_paths();
//		context.load_verify_file("certificate.pem");
//
//		mSSLSocket = new ssl::stream<ip::tcp::socket>(App::get()->io_service(), context);
//	}
//
//	void SendRequest(const std::string cHost, const std::string cURI)
//	{
//		tcp::resolver resolver(App::get()->io_service());
//		tcp::resolver::query query(cHost, "https");
//		resolver.async_resolve(query, std::bind(&HTTPSClient::HandleResolve, this,
//				std::placeholders::_1,//error
//				std::placeholders::_2,//iterator,
//				request));
//	}
//
//	void HandleResolve(const error_code &crError,
//			const iterator &criEndpoints, HTTPSRequest &rRequest)
//	{
//		async_connect(mSSLSocket->lowest_layer(), criEndpoints,
//				std::bind(&HTTPSClient::HandleConnect, this,
//						std::placeholders::_1,//error
//						rRequest//rRequest?
//                          ));
//	}
//
//	void HandleConnect(const error_code &crError, HTTPSRequest &rRequest)
//	{
//		mSSLSocket->lowest_layer().set_option(ip::tcp::no_delay(true));
//		mSSLSocket->set_verify_callback(ssl::rfc2818_verification(rRequest.mcHost));
//		mSSLSocket->handshake(ssl::stream_base::client);
//
//		// Form the request
//		std::stringstream requestStream;
//		requestStream << "POST " << rRequest.mcURI << " HTTP/1.1\r\n";
//		requestStream << "Host: " << rRequest.mcHost << "\r\n";
//		requestStream << "Accept: application/json\r\n";
//		requestStream << "Content-Type: application/json; charset=UTF-8\r\n";
//		std::string result = "{}";
//		requestStream << "Content-Length: " << result.length() << "\r\n";
//		requestStream << result << "\r\n\r\n";
//
////		write(*mSSLSocket, request);
//		write(*mSSLSocket, asio::buffer(requestStream.str()));
//
//		streambuf response;
//		read_until(*mSSLSocket, response, "\r\n");
//		std::istream responseStream(&response);
//
//	}
//
//};
