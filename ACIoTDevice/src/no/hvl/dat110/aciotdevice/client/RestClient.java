package no.hvl.dat110.aciotdevice.client;

import java.io.IOException;

import com.google.gson.Gson;
import okhttp3.*;


	public class RestClient {

		public RestClient() {
			// TODO Auto-generated constructor stub
		}

		private static String logpath = "/accessdevice/log";

		public void doPostAccessEntry(String message) {

			// TODO: implement a HTTP POST on the service to post the message
			OkHttpClient client = new OkHttpClient();

			Request request = new Request.Builder()
					.url("http://localhost:8080"+logpath)
					.post(RequestBody.create(MediaType.parse("text/plain"),message))
					.build();

			System.out.println(request.toString());

			try (Response response = client.newCall(request).execute()) {
				System.out.println (response.body().string());
			
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			
		}
		
		private static String codepath = "/accessdevice/code";
		
		public AccessCode doGetAccessCode() {

			AccessCode code = null;
			
			// TODO: implement a HTTP GET on the service to get current access code
			OkHttpClient client = new OkHttpClient();

			Request request = new Request.Builder()
					.url("http://localhost:8080"+codepath)
					.get()
					.build();

			System.out.println(request.toString());

			try (Response response = client.newCall(request).execute()) {
				Gson gson = new Gson();
				code = gson.fromJson(response.body().string(), AccessCode.class);
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			
			return code;
		}
	}

